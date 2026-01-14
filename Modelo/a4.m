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
u_filt = movmean(u_filt(idx,:), span);
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
opt.InitialState = 'zero';
opt.Focus = 'simulation';  
opt.EnforceStability = true;
opt.SearchMethod = 'gna';
optc = compareOptions('InitialCondition','estimate');

mm = ssest(data_tr,m,opt);
s_lo = pem(data_tr,mm,opt);  % modelo longitudinal

compare(data_va,s_lo,optc)
% revisar opciones  force stability gna etc