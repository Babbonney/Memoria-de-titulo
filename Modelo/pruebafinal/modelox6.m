clearvars
close all
clc

%% =======================
% 1. CARGA DE DATOS
%% =======================
d_motores = readtable('datps_actuator_outputs_0.csv');
d_vel     = readtable('datps_vehicle_angular_velocity_0.csv');
d_att     = readtable('datps_vehicle_attitude_0.csv');

t_m = d_motores.timestamp * 1e-6;
t_v = d_vel.timestamp     * 1e-6;
t_a = d_att.timestamp     * 1e-6;

t_m = t_m - t_m(1);
t_v = t_v - t_v(1);
t_a = t_a - t_a(1);

%% =======================
% 2. PROCESAMIENTO MOTORES
%% =======================
m1 = ((d_motores.output_0_ - 1100)/800) - 0.2691;
m2 = ((d_motores.output_1_ - 1100)/800) - 0.3501;
m3 = ((d_motores.output_2_ - 1100)/800) - 0.2498;
m4 = ((d_motores.output_3_ - 1100)/800) - 0.3462;

mixer = [-1  1  1 -1;
          1 -1  1 -1;
          1  1 -1 -1;
          1  1  1  1];

salida = mixer * [m1'; m2'; m3'; m4'];

u_raw = salida(1:3,:)';   % [roll pitch yaw]

%% =======================
% 3. SALIDAS ANGULARES
%% =======================
p = d_vel.xyz_0_;
q = d_vel.xyz_1_;
r = d_vel.xyz_2_;

q0 = d_att.q_0_;
q1 = d_att.q_1_;
q2 = d_att.q_2_;
q3 = d_att.q_3_;

phi   = atan2(2*(q0.*q1 + q2.*q3), q0.^2 - q1.^2 - q2.^2 + q3.^2);
theta = asin(-2*(q1.*q3 - q0.*q2));
psi   = atan2(2*(q1.*q2 + q0.*q3), q0.^2 + q1.^2 - q2.^2 - q3.^2);

%% =======================
% 4. SINCRONIZACIÓN
%% =======================
t_ref = t_v;

u = interp1(t_m, u_raw, t_ref, 'previous', 'extrap');
phi   = interp1(t_a, phi,   t_ref, 'previous', 'extrap');
theta = interp1(t_a, theta, t_ref, 'previous', 'extrap');
psi   = interp1(t_a, psi,   t_ref, 'previous', 'extrap');

y = [p q r phi theta psi];

%% =======================
% 5. LIMPIEZA
%% =======================
idx = all(~isnan([u y]),2);
u_clean = u(idx,:);
y_clean = y(idx,:);
t_ref   = t_ref(idx);

Ts = mean(diff(t_ref));
Ts = max(Ts,1e-3);

%% =======================
% 6. IDENTIFICACIÓN 3×3 (RATES)
%% =======================
data_tr = iddata(y_clean(:,1:3), u_clean, Ts);

m0 = idss(zeros(3), zeros(3,3), eye(3), zeros(3,3), zeros(3), 'Ts', Ts);
S = m0.Structure;
S.C.Free = false;
S.D.Free = false;
S.K.Free = false;
m0.Structure = S;

opt = ssestOptions;
opt.Focus = 'simulation';
opt.InitialState = 'estimate';

m_rates = ssest(data_tr, m0, opt);

%% =======================
% 7. CONSTRUCCIÓN MODELO 6×6
%% =======================
A3 = m_rates.A;
B3 = m_rates.B;

A6 = [ A3           zeros(3);
       eye(3)*Ts    eye(3) ];

B6 = [ B3;
       zeros(3,3) ];

C6 = eye(6);
D6 = zeros(6,3);

sys6 = ss(A6, B6, C6, D6, Ts);

%% =======================
% 8. SIMULACIÓN
%% =======================
N = size(u_clean,1);
t_sim = (0:N-1)'*Ts;

y_sim = lsim(sys6, u_clean, t_sim);

%% =======================
% 9. VALIDACIÓN
%% =======================
figure
for i = 1:3
    subplot(3,1,i)
    plot(t_sim, y_clean(:,i), t_sim, y_sim(:,i))
    grid on
end
legend('Real','Modelo')

%% =======================
% 10. MATRICES FINALES
%% =======================
disp('A6 ='); disp(A6)
disp('B6 ='); disp(B6)
