clearvars; close all; clc;

%% 1. CARGA DE DATOS
load("segundaprueba.mat")

% Definir rango
idx = 60000:length(motores.time)-80000;
t_raw = motores.time(idx,1);

%% 2. EXTRACCIÓN Y LIMPIEZA DINÁMICA
% Extraemos y forzamos a vector columna (N x 1) inmediatamente
m1 = motores.signals.values(idx,1) - 0.1344;
m2 = motores.signals.values(idx,2) - 0.2078;
m3 = motores.signals.values(idx,3) - 0.1551;
m4 = motores.signals.values(idx,4) - 0.2548;

u_raw = [ -(-m1+m2+m3-m4), (m1-m2+m3-m4), (m1+m2-m3-m4) ];

% Para las Y, usamos (:) para asegurar que sean columnas sin importar el squeeze
y1 = squeeze(rollrate.signals.values(1,1,idx));
y2 = squeeze(pitchrate.signals.values(1,1,idx));
y3 = squeeze(yawrate.signals.values(1,1,idx));
y_raw = [y1(:), y2(:), y3(:)];

%% 3. REDUCCIÓN POR BLOQUES (Downsampling Robusto)
% Si tienes 400,000 datos, un factor de 20 te deja 20,000 (perfecto para ssest)
factor = 20; 
num_muestras = floor(size(y_raw,1)/factor);

u_final = zeros(num_muestras, 3);
y_final = zeros(num_muestras, 3);
t_final = zeros(num_muestras, 1);

for i = 1:num_muestras
    rango = ((i-1)*factor + 1) : (i*factor);
    u_final(i,:) = mean(u_raw(rango,:), 1); % Promedio del bloque para reducir ruido
    y_final(i,:) = mean(y_raw(rango,:), 1);
    t_final(i)   = t_raw(rango(1));         % Tomamos el primer tiempo del bloque
end

%% 4. CREACIÓN DE TABLA Y EXPORTACIÓN
% Creamos variables independientes para asegurar que writetable no se confunda
Tiempo = t_final;
U1_Roll = u_final(:,1);
U2_Pitch = u_final(:,2);
U3_Yaw = u_final(:,3);
Y1_RollRate = y_final(:,1);
Y2_PitchRate = y_final(:,2);
Y3_YawRate = y_final(:,3);

T = table(Tiempo, U1_Roll, U2_Pitch, U3_Yaw, Y1_RollRate, Y2_PitchRate, Y3_YawRate);

% Intentar guardar
writetable(T, 'datos_finales.xlsx');

% Si writetable falla, esto guardará un .csv que Excel abre igual y es más ligero
writetable(T, 'datos_finales.csv');

save('datos_listos.mat', 'u_final', 'y_final', 't_final');

disp('--- PROCESO FINALIZADO ---');
fprintf('Muestras originales: %d\n', length(t_raw));
fprintf('Muestras reducidas: %d\n', length(t_final));
disp('Si el Excel falla, abre el archivo "datos_finales.csv" o "datos_listos.mat"');