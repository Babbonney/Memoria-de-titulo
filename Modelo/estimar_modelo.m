clearvars
close all
clc

%% cargar datos
% Ocupar funcion readtable para leer desde excel
tiempomotores = readtable('datosmotores.xlsx');
tiempovelocidades = readtable('datosvel.xlsx');
d_motores = readtable('prueba_actuator_outputs_0.csv');
d_vel = readtable('prueba_vehicle_angular_velocity_0.csv');
% Restar el valor de motor que elegiste y normalizar para este entre 0 y 1
% Pasar los motores a las acciones de control combinadas U
%35% de thrust 1100 1900 1380
tmin = 0.35;
m1 = (d_motores.output_0_-1100)./800;
m1 = (m1 - 0.35);
m2 = (d_motores.output_1_-1100)./800;
m2 = (m2 - 0.35);
m3 = (d_motores.output_2_-1100)./800;
m3 = (m3 - 0.35);
m4 = (d_motores.output_3_-1100)./800;
m4 = (m4 - 0.35);
% u1 = m1 - m2 - m3 + m4; %roll
% u2 = -m1 + m2 - m3 +m4; % pitch
% u3 = m1 + m2 - m3 - m4; % yaw
u1 = -m1 + m2 + m3 - m4; %roll
u2 = m1 - m2 + m3 -m4; % pitch
u3 = m1 + m2 - m3 - m4; % yaw
%interpolar velocidades porque tienen mas datos
t_ref = tiempomotores.Tsnormalizado;
t_vel = tiempovelocidades.tsNormalizado;
roll  = d_vel.xyz_0_;
pitch = d_vel.xyz_1_;
yaw   = d_vel.xyz_2_;

roll_i  = interp1(t_vel, roll,  t_ref, 'linear');
pitch_i = interp1(t_vel, pitch, t_ref, 'linear');
yaw_i   = interp1(t_vel, yaw,   t_ref, 'linear');
%limpieza post interpolacion
idx = ~isnan(roll_i) & ~isnan(pitch_i) & ~isnan(yaw_i) ...
      & ~isnan(u1) & ~isnan(u2) & ~isnan(u3);

roll_i  = roll_i(idx);
pitch_i = pitch_i(idx);
yaw_i   = yaw_i(idx);

u1 = u1(idx);
u2 = u2(idx);
u3 = u3(idx);

t_ref = t_ref(idx);

% RECORTAR PRIMEROS Y ÚLTIMOS 100 DATOS

recorte = 70; % número de datos a recortar
roll_i  = roll_i(recorte+1:end-recorte);
pitch_i = pitch_i(recorte+1:end-recorte);
yaw_i   = yaw_i(recorte+1:end-recorte);

u1 = u1(recorte+1:end-recorte);
u2 = u2(recorte+1:end-recorte);
u3 = u3(recorte+1:end-recorte);

t_ref = t_ref(recorte+1:end-recorte);

%crear vectores 
u = [u1 u2 u3];
velocidades = [roll_i pitch_i yaw_i];
%% generar variables de datos entrenamiento y validacion
Ts = mean(diff(t_ref));
% Ts = mean(diff(t_ref));

% 70% entrenamiento, y 30% validacion
N   = length(t_ref);
Ntr = floor(0.7*N);

u_tr = u(1:Ntr,:);
y_tr = velocidades(1:Ntr,:);

u_va = u(Ntr+1:end,:);
y_va = velocidades(Ntr+1:end,:);

data_entrlo = iddata(y_tr, u_tr, Ts);
data_vallo  = iddata(y_va, u_va, Ts);

%% estimar modelo
A_lo = zeros(3);
B_lo = zeros(3);
C_lo = eye(3);
D_lo = zeros(3);
K_lo = zeros(3);

m = idss(A_lo,B_lo,C_lo,D_lo,K_lo,'Ts',Ts);

S = m.Structure;
S.C.Free = false; 
S.D.Free = false; 
S.K.Free = false;  
%S.B.Free(1,2) = false; S.B.Free(2,2) = false; 
%S.B.Free(3,1) = false; %S.B.Free(4,1) = false;
m.Structure = S;

% configuracion del system identification
opt = ssestOptions;
opt.InitializeMethod = 'n4sid';
opt.InitialState = 'estimate';
opt.Focus = 'simulation';  
opt.EnforceStability = true;
opt.SearchMethod = 'lm';
optc = compareOptions('InitialCondition','estimate');

mm = ssest(data_entrlo,m,opt);
s_lo = pem(data_entrlo,mm,opt);  % modelo longitudinal 

% % compare: compara el modelo con los datos de validacion 
compare(data_vallo,s_lo,optc)
% % 1. Ver el mapa de polos y ceros (¿Es el modelo físicamente posible?)
% figure;
% pzmap(s_lo);
% title('Polos del modelo identificado (Deben estar dentro del círculo)');
% 
% % 2. Ver la respuesta al escalón de los datos identificados
% figure;
% step(s_lo);
% title('Respuesta al escalón del modelo (¿Tienen sentido las magnitudes?)');
% 
% % 3. Ver el residuo (Si hay mucha correlación, el modelo es pobre)
% figure;
% resid(data_vallo, s_lo);
