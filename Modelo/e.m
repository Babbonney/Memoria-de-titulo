clearvars; close all; clc;

%% 1. CARGA DE DATOS
tiempomotores = readtable('datosmotores.xlsx');
tiempovelocidades = readtable('datosvel.xlsx');
d_motores = readtable('prueba_actuator_outputs_0.csv');
d_vel = readtable('prueba_vehicle_angular_velocity_0.csv');

%% 2. PROCESAMIENTO DE MOTORES
m1 = (d_motores.output_0_ - 1100) ./ 800 - 0.35;
m2 = (d_motores.output_1_ - 1100) ./ 800 - 0.35;
m3 = (d_motores.output_2_ - 1100) ./ 800 - 0.35;
m4 = (d_motores.output_3_ - 1100) ./ 800 - 0.35;

u1_raw = -m1 + m2 + m3 - m4; % Roll
u2_raw =  m1 - m2 + m3 - m4; % Pitch
u3_raw =  m1 + m2 - m3 - m4; % Yaw

%% 3. SINCRONIZACIÓN INICIAL
t_vel_orig = tiempovelocidades.tsNormalizado - tiempovelocidades.tsNormalizado(1);
t_mot_orig = tiempomotores.Tsnormalizado - tiempomotores.Tsnormalizado(1);
t_ref = t_vel_orig; 

u1 = interp1(t_mot_orig, u1_raw, t_ref, 'previous', 'extrap');
u2 = interp1(t_mot_orig, u2_raw, t_ref, 'previous', 'extrap');
u3 = interp1(t_mot_orig, u3_raw, t_ref, 'previous', 'extrap');

y_raw = [d_vel.xyz_0_, d_vel.xyz_1_, d_vel.xyz_2_];

%% 4. PRE-PROCESAMIENTO AVANZADO
% A. Limpieza de NaNs
idx = ~isnan(y_raw(:,1)) & ~isnan(u1);
y_clean = y_raw(idx,:);
u_clean = [u1(idx), u2(idx), u3(idx)];
t_ref = t_ref(idx);

% B. Remoción de Outliers (Picos de vibración)
y_clean = filloutliers(y_clean, 'linear', 'movmedian', 30);

% C. Cálculo robusto de Ts y fs
Ts = mean(diff(t_ref));
if Ts <= 0 || isnan(Ts), Ts = 0.01; end % Protección contra Ts inválido
fs = 1/Ts;

% D. Filtro Butterworth de Fase Cero (Protegido)
fc = 4; % Frecuencia de corte en Hz
Wn = fc / (fs/2); 
if Wn >= 1, Wn = 0.99; end % Evita el error en la función butter

[b, a] = butter(2, Wn); 
y_clean = filtfilt(b, a, y_clean);
u_clean = filtfilt(b, a, u_clean);

% E. Alineación de Retardo (Time Delay Alignment)
% Comparamos Roll (u1) con p (y1) para encontrar el lag físico
[corr, lags] = xcorr(y_clean(:,1), u_clean(:,1));
[~, max_idx] = max(abs(corr));
delay_samples = lags(max_idx);

if delay_samples > 0
    y_clean = y_clean(delay_samples+1:end, :);
    u_clean = u_clean(1:end-delay_samples, :);
    t_ref = t_ref(1:end-delay_samples);
    fprintf('Retardo detectado y corregido: %d muestras (%.3f s)\n', delay_samples, delay_samples*Ts);
end

% F. Detrend (Eliminar componentes de DC/Offset)
y_clean = detrend(y_clean);
u_clean = detrend(u_clean);

% G. Recorte Final y División de Datos
recorte = 5000; 
recorte2 = 300;
y_final = y_clean(recorte+1:end-recorte2, :);
u_final = u_clean(recorte+1:end-recorte2, :);

data_tr = iddata(y_final(1:floor(0.7*end), :), u_final(1:floor(0.7*end), :), Ts);
data_va = iddata(y_final(floor(0.7*end)+1:end, :), u_final(floor(0.7*end)+1:end, :), Ts);

%% 5. ESTIMACIÓN DEL MODELO (ORDEN 3)
% Definir estructura base de Espacio de Estados
m_base = idss(zeros(3), zeros(3), eye(3), zeros(3), zeros(3), 'Ts', Ts);
S = m_base.Structure;
S.C.Free = false; 
S.D.Free = false; 
S.K.Free = false; 
% S.B.Free = [true false false; false true false; false false true]; % Opcional: Desacoplar B
m_base.Structure = S;

% Configuración del algoritmo de identificación
opt = ssestOptions;
opt.InitializeMethod = 'n4sid';
opt.InitialState = 'estimate';
opt.Focus = 'simulation';  
opt.EnforceStability = true;
opt.SearchMethod = 'gn'; % Levenberg-Marquardt para mayor robustez

% Estimación
mm = ssest(data_tr, m_base, opt);
s_lo = pem(data_tr, mm, opt); % Refinamiento final

%% 6. VALIDACIÓN Y GRÁFICOS
optc = compareOptions('InitialCondition', 'estimate');
figure('Name', 'Validación del Modelo', 'Color', 'w');
compare(data_va, s_lo, optc);

% Análisis de Residuos
figure('Name', 'Análisis de Residuos');
resid(data_va, s_lo);

% Mapa de Polos y Ceros
figure('Name', 'Mapa de Polos y Ceros');
pzmap(s_lo);
title('Polos y Ceros del modelo identificado');

% Mostrar Matrices Finales para el MPC
disp('--- MATRICES IDENTIFICADAS ---');
fprintf('Matriz A:\n'); disp(s_lo.A);
fprintf('Matriz B:\n'); disp(s_lo.B);