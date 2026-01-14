clearvars
close all
clc

%% Modelo dron discreto
Ac = [    0.8477    1.2578    0.7742;
   -0.1984    0.3349   -0.2449;
   -0.0116   -0.0807    0.3575;];
Bc = [   -1.0208    0.2231   -0.2286;
   -0.1248   -0.1256    0.0655;
   -0.0482    0.0832    0.2842];
Ts = 0.1;

sysc = ss(Ac,Bc,[],[]);
sysd = c2d(sysc,Ts);
A = sysd.A;
B = sysd.B;

[nx, nu] = size(B); % nx=3 estados, nu=3 entradas

%% Costos LQR (para P final)
Q = diag([1 1 1]);         % penaliza roll, pitch, yaw
R = diag([0.01 0.01 0.01]); % penaliza control
K = -dlqr(A,B,Q,R);
P = dare(A,B,Q,R); % costo final

%% Horizonte MPC
N = 5; % pasos de predicción

% Matrices de costo para QP
Qbar = kron(eye(N-1), Q);
Qbar = blkdiag(Qbar, P);   % incluye costo final
Rbar = kron(eye(N), R);

% Matrices de predicción
F = zeros(N*nx, nx);
G = zeros(N*nx, N*nu);
for i = 1:N
    F((i-1)*nx+1:i*nx,:) = A^i;
    for j = 1:i
        G((i-1)*nx+1:i*nu,(j-1)*nu+1:j*nu) = A^(i-j)*B;
    end
end

H = G'*Qbar*G + Rbar; % Hessiano QP

%% Restricciones
x_max = 20; % rad/s
F_x = [eye(nx); -eye(nx)];       % 6x3
g_x = [x_max*ones(nx,1); x_max*ones(nx,1)];

u_max = 1; % normalizado entre 0 y 1
F_u = [eye(nu); -eye(nu)];       % 6x3
g_u = [u_max*ones(nu,1); u_max*ones(nu,1)];

% Restricciones para el QP (sobre u_horizon)
F_cons = kron(eye(N), F_x) * G;  % tamaño: 6*N x nu*N

%% Estímulo / Setpoint
Tsim = 1000;  % número de pasos de simulación
ref = zeros(nx, Tsim); 
ref(:, 10:end) = repmat([5; 2; -3], 1, Tsim-9); % escalón a t=10*Ts

%% Simulación MPC
x(:,1) = [0; 0; 0]; % estado inicial
u = zeros(nu, Tsim);

options = optimset('Display','off');

for k = 1:Tsim
    % Error respecto a setpoint
    x_error = x(:,k) - ref(:,k);

    % Vector lineal f para QP
    f = (2*(F*x_error)'*Qbar*G)';

    % g_QP depende del estado actual
    g_QP = repmat(g_x, N, 1) - kron(eye(N), F_x) * F * x_error;

    % Resolver QP
    u_horizon = quadprog(2*H, f, F_cons, g_QP, [], [], [], [], [], options);

    % Tomar solo primera acción
    u(:,k) = u_horizon(1:nu);

    % Propagar sistema
    x(:,k+1) = A*x(:,k) + B*u(:,k);
end

%% Graficar resultados
time = 0:Ts:Tsim*Ts;

figure;
plot(time, x'); hold on;
plot(time, [ref ref(:,end)]', '--','LineWidth',1.5); % setpoint
xlabel('Tiempo [s]');
ylabel('Velocidades angulares [rad/s]');
legend('RollRate','PitchRate','YawRate','Ref Roll','Ref Pitch','Ref Yaw');
grid on;

figure;
plot(time(1:end-1), u');
xlabel('Tiempo [s]');
ylabel('Entradas normalizadas');
legend('u1','u2','u3');
grid on;
