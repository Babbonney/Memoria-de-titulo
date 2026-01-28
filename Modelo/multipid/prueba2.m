clearvars; clc; close all;

%% 1. CARGA DE DATOS
d_motores = readtable('datos_finales.xlsx');
u_clean = [d_motores.U1_Roll, d_motores.U2_Pitch, d_motores.U3_Yaw];
y_clean = [d_motores.Y1_RollRate, d_motores.Y2_PitchRate, d_motores.Y3_YawRate];
Ts = (d_motores.Tiempo(2) - d_motores.Tiempo(1));

% C. Cálculo robusto de Ts y fs
if Ts <= 0 || isnan(Ts), Ts = 0.01; end % Protección contra Ts inválido
fs = 1/Ts;

% D. Filtro Butterworth de Fase Cero (Protegido)
fc = 10; % Frecuencia de corte en Hz
Wn = fc / (fs/2); 
if Wn >= 1, Wn = 0.99; end % Evita el error en la función butter

[b, a] = butter(2, Wn); 
y_clean = filtfilt(b, a, y_clean);
u_clean = filtfilt(b, a, u_clean);
%% 2. ALINEACIÓN DE RETARDO (Cross-Correlation)
n_outputs = size(y_clean, 2);
delays = zeros(1, n_outputs);

% Calculamos el lag óptimo para cada canal
for i = 1:n_outputs
    [corr, lags] = xcorr(y_clean(:,i), u_clean(:,i));
    [~, max_idx] = max(abs(corr));
    delays(i) = lags(max_idx);
    fprintf('Eje %d - Retardo detectado: %d muestras\n', i, delays(i));
end

% Sincronización robusta:
% Para evitar problemas de dimensiones, buscamos el desfase máximo
max_d = max(abs(delays));
N = size(y_clean, 1);

% Reservamos espacio para los datos alineados
% El recorte (max_d) en ambos extremos asegura que no queden ceros por el desfase
y_aligned = [];
u_aligned = [];

for i = 1:n_outputs
    d = delays(i);
    % Rango de índices seguro para sincronizar
    % Si d=5, u está adelantada 5 muestras; tomamos y(6:end) y u(1:end-5)
    idx_y = (max_d + 1) : (N - max_d);
    idx_u = (max_d + 1 - d) : (N - max_d - d);
    
    y_aligned(:,i) = y_clean(idx_y, i);
    u_aligned(:,i) = u_clean(idx_u, i);
end

%% 3. PREPARACIÓN PARA IDENTIFICACIÓN
% Usamos los datos ya alineados
data_total = iddata(y_aligned, u_aligned, Ts);

% División 70/30 para Entrenamiento y Validación
data_tr = data_total(1:floor(0.7*end));
data_va = data_total(floor(0.7*end)+1:end);

%% 4. DEFINICIÓN DEL MODELO (idss)
% Definir estructura base (3 estados para 3 salidas/entradas)
m_base = idss(zeros(3), zeros(3), eye(3), zeros(3), zeros(3), 'Ts', Ts);
S = m_base.Structure;
S.C.Free = false; % C es identidad (estados = salidas directas)
S.D.Free = false; % Sin paso directo
S.K.Free = false; % Sin ruido de proceso para el MPC básico
m_base.Structure = S;

%% 5. ESTIMACIÓN
opt = ssestOptions;
opt.InitializeMethod = 'n4sid';
opt.InitialState = 'estimate';
opt.Focus = 'simulation';  
opt.EnforceStability = false; 
opt.SearchMethod = 'fmincon';     

mm = ssest(data_tr, m_base, opt);
s_lo = pem(data_tr, mm, opt); % Refinamiento final

%% 6. VALIDACIÓN Y GRÁFICOS
figure('Name', 'Validación del Modelo Alineado', 'Color', 'w');
optc = compareOptions('InitialCondition', 'estimate');
compare(data_va, s_lo, optc);

% Mostrar Resultados
disp('--- RESULTADOS DE IDENTIFICACIÓN ---');
fprintf('Ajuste (Fit): %.2f%%\n', s_lo.Report.Fit.FitPercent);
disp('Matriz A:'); disp(s_lo.A);
disp('Matriz B:'); disp(s_lo.B);

% Verificar estabilidad final
if isstable(s_lo)
    disp('Confirmado: El modelo es estable.');
else
    warning('El modelo identificado es INESTABLE.');
end