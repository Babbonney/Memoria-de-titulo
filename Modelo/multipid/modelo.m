clearvars
close all; 
clc;

%% 1. CARGA DE DATOS
load("segundaprueba.mat")
tiempo= motores.time(60000:end-80000,1);
%% 2. PROCESAMIENTO DE MOTORES
m1 = motores.signals.values(60000:end-80000,1) - 0.1344;
m2 = motores.signals.values(60000:end-80000,2)- 0.2078;
m3 = motores.signals.values(60000:end-80000,3) - 0.1551;
m4 = motores.signals.values(60000:end-80000,4) - 0.2548;
u1 = -(-m1 + m2 + m3 - m4); % Roll
u2 =  (m1 - m2 + m3 - m4); % Pitch
u3 =  m1 + m2 - m3 - m4; % Yaw

%% 3. SINCRONIZACIÓN INICIAL
t_ref = tiempo ;
y1 = squeeze(rollrate.signals.values(1,1,60000:end-80000));
y2 = squeeze(pitchrate.signals.values(1,1,60000:end-80000));
y3 = squeeze(yawrate.signals.values(1,1,60000:end-80000));
y_raw = [y1, y2, y3];
% y_raw = [squeeze(rollrate.signals.values(1,1,60000:end-80000)), squeeze(pitchrate.signals.values(1,1,60000:end-80000)), squeeze(pitchrate.signals.values(1,1,60000:end-80000))];

%% 4. PRE-PROCESAMIENTO AVANZADO
% A. Limpieza de NaNs
idx = ~isnan(y_raw(:,1)) & ~isnan(u1);
y_clean = y_raw(idx,:);
u_clean = [u1(idx), u2(idx), u3(idx)];
t_ref = t_ref(idx);

% % B. Remoción de Outliers (Picos de vibración)
% % y_clean = filloutliers(y_clean, 'linear', 'movmedian', 30);
% 
% % C. Cálculo robusto de Ts y fs
Ts = mean(diff(t_ref));

% if Ts <= 0 || isnan(Ts), Ts = 0.01; end % Protección contra Ts inválido
% fs = 1/Ts;
% 
% % D. Filtro Butterworth de Fase Cero (Protegido)
% fc = 4; % Frecuencia de corte en Hz
% Wn = fc / (fs/2); 
% if Wn >= 1, Wn = 0.99; end % Evita el error en la función butter
% 
% [b, a] = butter(2, Wn); 
% y_clean = filtfilt(b, a, y_clean);
% u_clean = filtfilt(b, a, u_clean);
% a
% E. Alineación de Retardo (Time Delay Alignment)
% Comparamos Roll (u1) con p (y1) para encontrar el lag físico
% [corr, lags] = xcorr(y_clean(:,1), u_clean(:,1));
% [~, max_idx] = max(abs(corr));
% delay_samples = lags(max_idx);
% 
% if delay_samples < 0
%     % Caso común: La salida parece adelantada (error de sincronización de timestamps)
%     d = abs(delay_samples);
%     y_clean = y_clean(d+1:end, :);
%     u_clean = u_clean(1:end-d, :);
%     t_ref = t_ref(1:end-d);
%     fprintf('Retardo negativo corregido (Salida adelantada): %d muestras\n', d);
% elseif delay_samples > 0
%     % Caso: La entrada está adelantada (lo normal físicamente)
%     y_clean = y_clean(1:end-delay_samples, :);
%     u_clean = u_clean(delay_samples+1:end, :);
%     t_ref = t_ref(1:end-delay_samples);
%     fprintf('Retardo positivo corregido (Entrada adelantada): %d muestras\n', delay_samples);
% end
% E. Alineación de Retardo Multivariable (Eje por Eje)
% n_outputs = size(y_clean, 2);
% delays = zeros(1, n_outputs);
% 
% % Calculamos el lag óptimo para cada canal (1:Roll, 2:Pitch, 3:Yaw)
% for i = 1:n_outputs
%     [corr, lags] = xcorr(y_clean(:,i), u_clean(:,i));
%     [~, max_idx] = max(abs(corr));
%     delays(i) = lags(max_idx);
%     fprintf('Eje %d - Retardo detectado: %d muestras\n', i, delays(i));
% end
% 
% % Para sincronizar todos, buscamos el desplazamiento máximo necesario
% max_d = max(abs(delays));
% y_aligned = [];
% u_aligned = [];
% 
% for i = 1:n_outputs
%     d = delays(i);
%     % Ajustamos cada señal individualmente según su propio delay
%     % Si d > 0, la entrada u se desplaza a la derecha (u es causa)
%     % Si d < 0, la salida y se desplaza a la derecha (y parece adelantada)
% 
%     start_u = max_d + 1 - d;
%     end_u   = size(u_clean, 1) - (max_d + d);
% 
%     % Nota: Para simplificar y mantener la coherencia temporal, 
%     % aplicamos un recorte uniforme basado en el retardo máximo
%     idx_y = (max_d + 1) : (size(y_clean,1) - max_d);
%     idx_u = (max_d + 1 - d) : (size(u_clean,1) - max_d - d);
% 
%     temp_y = y_clean(idx_y, i);
%     temp_u = u_clean(idx_u, i);
% 
%     y_aligned(:,i) = temp_y;
%     u_aligned(:,i) = temp_u;
% end

% y_clean = y_aligned;
% u_clean = u_aligned;
t_ref = (0:size(y_clean,1)-1)' * Ts; % Regeneramos vector de tiempo

% F. Detrend (Eliminar componentes de DC/Offset)
% y_clean = detrend(y_clean);
% u_clean = detrend(u_clean);
y_final = y_clean;
u_final = u_clean;
data_tr = iddata(y_final(1:floor(0.7*end), :), u_final(1:floor(0.7*end), :), Ts);
data_tr = resample(data_tr,1,20);
umbral = 1e-5; % O un valor ligeramente menor al ruido de tu sensor
data_tr.y(abs(data_tr.y(:,3)) < umbral, 3) = umbral;
data_va = iddata(y_final(floor(0.7*end)+1:end, :), u_final(floor(0.7*end)+1:end, :), Ts);
data_va = resample(data_va,1,20);
data_va.y(abs(data_va.y(:,3)) < umbral, 3) = umbral;
Ts= Ts*20;
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
inicial=[y_final(1,1);y_final(1,2);y_final(1,3)];
opt = ssestOptions;
opt.InitializeMethod = 'n4sid';
% opt.InitialState = inicial;
opt.InitialState = 'estimate';
opt.Focus = 'prediction';  
opt.EnforceStability = false;
opt.SearchMethod = 'gn'; 
% Estimación
mm = ssest(data_tr, m_base, opt);
s_lo = pem(data_tr, mm, opt); % Refinamiento final
%% 6. VALIDACIÓN Y GRÁFICOS
optc = compareOptions('InitialCondition', 'estimate');
figure('Name', 'Validación del Modelo', 'Color', 'w');
compare(data_va, s_lo, optc);

% % Análisis de Residuos
% figure('Name', 'Análisis de Residuos');
% resid(data_va, s_lo);

% % Mapa de Polos y Ceros
% figure('Name', 'Mapa de Polos y Ceros');
% pzmap(s_lo);
% title('Polos y Ceros del modelo identificado');

% Mostrar Matrices Finales para el MPC
disp('--- MATRICES IDENTIFICADAS ---');
fprintf('Matriz A:\n'); disp(s_lo.A);
fprintf('Matriz B:\n'); disp(s_lo.B);

s_lo.Report.Fit.FitPercent


% Matriz A:

% 
% Matriz B:

% 
% 
% ans =
% 
%    34.9586
%    39.4762
%    35.1334