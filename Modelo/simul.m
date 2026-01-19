clear all; clc; close all;

%% 1. MATRICES DEL SISTEMA
A = [1.333650695949998, -1.668714910244021,  5.632342547392557;
     1.220605709316355, -1.768083035175748,  2.980769476932811;
     0.324324414735769, -0.426047177599778, -0.281734621621188];

B = [-2.122185994762327, -1.353681217245696, -1.462094492977615;
     -1.013280130692134, -1.854604300287162, -0.351287697129404;
      0.578625448174987, -0.128607817414752,  0.510736009980700];

n_estados = 3; n_entradas = 3;
Ts = 0.01; Pasos = 400; 
N = 5; % Horizonte de predicción

x = [0; 0; 0]; 

%% 2. PESOS Y MATRICES EXPANDIDAS
Q_inst = eye(n_estados) * 15;   % Peso en el error de estado
R_inst = diag([0.5, 0.5, 1]);   % Penalización al movimiento de motores

F = zeros(n_estados*N, n_estados);
Phi = zeros(n_estados*N, n_entradas*N);
Q_big = zeros(n_estados*N, n_estados*N);
R_big = zeros(n_entradas*N, n_entradas*N);

for i = 1:N
    F((i-1)*n_estados+1:i*n_estados, :) = A^i;
    Q_big((i-1)*n_estados+1:i*n_estados, (i-1)*n_estados+1:i*n_estados) = Q_inst;
    R_big((i-1)*n_entradas+1:i*n_entradas, (i-1)*n_entradas+1:i*n_entradas) = R_inst;
    for j = 1:i
        Phi((i-1)*n_estados+1:i*n_estados, (j-1)*n_entradas+1:j*n_entradas) = A^(i-j) * B;
    end
end

H = 2 * (Phi' * Q_big * Phi + R_big);
options = optimoptions('quadprog', 'Display', 'off');

% Límites de los mandos u
lb = repmat([-1.2; -1.2; -1.2], N, 1);
ub = repmat([ 1.2;  1.2;  1.2], N, 1);

%% 3. DEFINICIÓN DEL IMPULSO
% Generamos un pulso de 0.5 rad/s en Roll solo entre t=0.5s y t=0.7s
hist_ref = zeros(n_estados, Pasos);
inicio_impuso = floor(0.5/Ts);
fin_impulso = floor(0.7/Ts);
hist_ref(1, inicio_impuso:fin_impulso) = 0.5; 

%% 4. INICIALIZACIÓN DE HISTORIAL
hist_x = zeros(n_estados, Pasos);
hist_pwm = zeros(4, Pasos);
M = [-1,  1,  1,  1; 
      1, -1,  1,  1; 
      1,  1, -1,  1; 
     -1, -1, -1,  1]; 

%% 5. BUCLE DE SIMULACIÓN
for k = 1:Pasos
    ref_k = hist_ref(:, k);
    hist_x(:, k) = x;
    
    % Cálculo de f con referencia futura constante en el horizonte N
    Ref_seq = repmat(ref_k, N, 1);
    f = (2 * Phi' * Q_big * F * x) - (2 * Phi' * Q_big * Ref_seq);
    
    % Resolver QP
    [U_sol, ~, exitflag] = quadprog(H, f, [], [], [], [], lb, ub, [], options);
    
    if exitflag < 1, u = zeros(3,1); else, u = U_sol(1:3); end
    
    % --- DESMEZCLA Y PWM ---
    u_total = [u(1); u(2); u(3); 1.4]; % 1.4 es el throttle base
    m = M * u_total; 
    pwm_final = max(min(m * 800 + 1100, 1900), 1100);
    hist_pwm(:, k) = pwm_final;
    
    % Simulación del paso
    x = A * x + B * u;
end

%% 6. GRÁFICOS
t = (0:Pasos-1)*Ts;
figure('Color', 'w', 'Position', [100, 50, 900, 700]);

subplot(2,1,1);
plot(t, hist_x(1,:), 'r', 'LineWidth', 2); hold on;
plot(t, hist_x(2,:), 'g', 'LineWidth', 1.5);
plot(t, hist_x(3,:), 'b', 'LineWidth', 1.5);
plot(t, hist_ref(1,:), '--k', 'LineWidth', 1);
title('Respuesta al Impulso (Velocidades Angulares)');
ylabel('rad/s'); legend('Roll (p)', 'Pitch (q)', 'Yaw (r)', 'Referencia'); grid on;

subplot(2,1,2);
plot(t, hist_pwm', 'LineWidth', 1.2);
title('Señales PWM de los Motores');
ylabel('PWM (us)'); xlabel('Tiempo (s)'); grid on;