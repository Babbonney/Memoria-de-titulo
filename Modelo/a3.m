clearvars
close all
clc

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

%% 3. SINCRONIZACIÓN
t_vel_orig = tiempovelocidades.tsNormalizado - tiempovelocidades.tsNormalizado(1);
t_mot_orig = tiempomotores.Tsnormalizado - tiempomotores.Tsnormalizado(1);
t_ref = t_vel_orig; 

u1 = interp1(t_mot_orig, u1_raw, t_ref, 'previous', 'extrap');
u2 = interp1(t_mot_orig, u2_raw, t_ref, 'previous', 'extrap');
u3 = interp1(t_mot_orig, u3_raw, t_ref, 'previous', 'extrap');
u1=[u1(2:end);u1(end)];
u2=[u2(2:end);u2(end)];
u3=[u3(2:end);u3(end)];

y_raw = [d_vel.xyz_0_, d_vel.xyz_1_, d_vel.xyz_2_];

%% 4. PRE-PROCESAMIENTO
idx = ~isnan(y_raw(:,1)) & ~isnan(u1);
span = 12; 
y_filt = movmean(y_raw(idx,:), span);
u_filt = [u1(idx), u2(idx), u3(idx)];
t_ref = t_ref(idx);

y_clean = detrend(y_filt);
u_clean = detrend(u_filt);

recorte = 430; 
y_final = y_clean(recorte+1:end-recorte, :);
u_final = u_clean(recorte+1:end-recorte, :);
t_ref   = t_ref(recorte+1:end-recorte);

Ts = mean(diff(t_ref));
data_tr = iddata(y_final(1:floor(0.7*end), :), u_final(1:floor(0.7*end), :), Ts);
data_va = iddata(y_final(floor(0.7*end)+1:end, :), u_final(floor(0.7*end)+1:end, :), Ts);

%% 5. DEFINICIÓN MANUAL DE LA ESTRUCTURA (C=Identidad, K=0)
nx = 3; % Para que C sea identidad 3x3, el orden debe ser 3
ny = 3;
nu = 3;

% Inicializamos matrices A y B aleatorias o con n4sid
opt_n4 = n4sidOptions('Focus', 'simulation', 'InitialState', 'zero');
sys_temp = n4sid(data_tr, nx, opt_n4);
asads
% Creamos el modelo idss manualmente
% C = eye(3) -> Los estados son directamente las velocidades angulares
% K = zeros(3) -> No hay modelo de ruido
m = idss(sys_temp.A, sys_temp.B, eye(ny), zeros(ny, nu), zeros(nx, ny), 'Ts', Ts);

% Configurar restricciones estructurales
m.Structure.A.Free = true;
m.Structure.B.Free = true;
m.Structure.C.Free = false; % Bloqueada como Identidad
m.Structure.D.Free = false; % Bloqueada en Cero
m.Structure.K.Free = false; % Bloqueada en Cero

% 6. REFINAMIENTO
opt_ss = ssestOptions;
opt_ss.Focus = 'simulation';
opt_ss.SearchMethod = 'lm';
opt_ss.Display = 'on';

s_lo = ssest(data_tr, m, opt_ss);

%% 7. VISUALIZACIÓN
figure('Name', 'Validación del Modelo');
compare(data_va, s_lo, 10);

[A, B, C, D, K] = ssdata(s_lo);
disp('Matriz C (debe ser identidad):'); disp(C);
disp('Matriz K (debe ser ceros):'); disp(K);