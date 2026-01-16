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

% MANTENIENDO EL DESPLAZAMIENTO DE U QUE SOLICITASTE
u1 = [u1(2:end); u1(end)];
u2 = [u2(2:end); u2(end)];
u3 = [u3(2:end); u3(end)];

y_raw = [d_vel.xyz_0_, d_vel.xyz_1_, d_vel.xyz_2_];

%% 4. PRE-PROCESAMIENTO
idx = ~isnan(y_raw(:,1)) & ~isnan(u1);
span = 6; 

y_filt = movmean(y_raw(idx,:), span);
u_filt = [u1(idx), u2(idx), u3(idx)];
u_filt = movmean(u_filt, span); % Ajustado para usar la matriz indexada

t_ref = t_ref(idx);
y_clean = detrend(y_filt);
u_clean = detrend(u_filt);

recorte = 600; 
y_final = y_clean(recorte+1:end-recorte, :);
u_final = u_clean(recorte+1:end-recorte, :);
t_ref   = t_ref(recorte+1:end-recorte);

Ts = mean(diff(t_ref));

% División de datos
n_split = floor(0.7 * length(y_final));
data_tr = iddata(y_final(1:n_split, :), u_final(1:n_split, :), Ts);
data_va = iddata(y_final(n_split+1:end, :), u_final(n_split+1:end, :), Ts);

%% 5. ESTIMAR MODELO ORDEN 6 (3 Entradas / 3 Salidas)
nx = 6; % Orden del sistema
nu = 3; % Roll, Pitch, Yaw
ny = 3; % p, q, r

% Definición de estructura idss
A_init = zeros(nx);
B_init = zeros(nx, nu);
% Fijamos C: los primeros 3 estados son p, q, r. Los otros 3 son estados internos libres.
C_init = [eye(ny), zeros(ny, nx-ny)]; 
D_init = zeros(ny, nu);
K_init = zeros(nx, ny);

m = idss(A_init, B_init, C_init, D_init, K_init, 'Ts', Ts);

% Configuración de restricciones: C NO ES LIBRE
S = m.Structure;
S.C.Value = C_init;
S.C.Free = false; 
S.D.Free = false; 
S.K.Free = false; 
m.Structure = S;

% Opciones de identificación
opt = ssestOptions;
opt.InitializeMethod = 'n4sid';
opt.InitialState = 'estimate';
opt.Focus = 'simulation';  
opt.EnforceStability = true; % Recomendado para orden 6
opt.SearchMethod = 'gn';

% Estimación
mm = ssest(data_tr, m, opt);
s_lo = pem(data_tr, mm, opt); % Refinamiento con PEM

%% 6. VALIDACIÓN
optc = compareOptions('InitialCondition', 'estimate');
figure('Name', 'Validación del Modelo Orden 6 - C Fija');
compare(data_va, s_lo, optc);

% Verificación de matrices para el MPC
A_dis = s_lo.A;
B_dis = s_lo.B;
C_dis = s_lo.C;

disp('Tamaño de Matriz A (debería ser 6x6):');
disp(size(A_dis));
disp('Matriz C (debería mantener la identidad en la izquierda):');
disp(C_dis);

%% 7. SIGUIENTE PASO
% Estas matrices A_dis y B_dis son las que debes copiar a tu bloque MPC.
% Recuerda que el vector de estado x en el MPC ahora debe ser de 6x1.