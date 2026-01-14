clear all; clc; close all;

% 1. Matrices del sistema
A = [0.9347, 0.0728, 0.6931; 0.0043, 0.9492, 0.1273; -0.0283, -0.0333, 0.7369];
B = [0.0094, -0.0779, -0.2379; -0.0359, 0.1212, -0.0441; 0.1047, 0.0299, 0.0955];

n_estados = 3; n_entradas = 3;
Ts = 0.01; Pasos = 150; 
N = 6; % <--- NUEVO: Horizonte de predicción

x = [0; 0; 0]; referencia = [0; 0; 0]; 

% 2. Pesos del controlador (Mantenemos tus valores equilibrados)
Q_inst = eye(n_estados) * 1; 
R_inst = eye(n_entradas) * 10; 

% --- CONSTRUCCIÓN DE MATRICES MPC (HORIZONTE N=6) ---
% Esto expande el problema para mirar 6 pasos adelante
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
F_f = 2 * Phi' * Q_big * F;

% Límites (expandidos al horizonte)
v_max = 60; 
lb = repmat([-2; -2; -2], N, 1);
ub = repmat([ 2;  2;  2], N, 1);
options = optimoptions('quadprog', 'Display', 'off');

% 3. Inicialización de gráficas
hist_x = zeros(n_estados, Pasos);
hist_pwm = zeros(4, Pasos);
M = [-1, 1, 1, -1; 1, -1, 1, -1; 1, 1, -1, -1; 1, 1, 1, 1];

% 4. Bucle de simulación
for k = 1:Pasos
    if k == 40, x = x + [15; 0; 0]; end 
    
    hist_x(:, k) = x;
    
    % Cálculo de f para el horizonte completo
    Ref_seq = repmat(referencia, N, 1);
    f = F_f * x - 2 * Phi' * Q_big * Ref_seq;
    
    % Resolvemos para los 6 pasos futuros
    [U_sol, ~, exitflag] = quadprog(H, f, [], [], [], [], lb, ub, [], options);
    
    if exitflag < 1, u = zeros(3,1); else, u = U_sol(1:3); end
    
    % --- DESMEZCLA ---
    u_total = [u(1); u(2); u(3); 1.4]; 
    m = M \ u_total; 
    pwm_final = max(min(m * 800 + 1100, 1900), 1100);
    hist_pwm(:, k) = pwm_final;
    
    % Simulación del sistema real
    x = A * x + B * u;
end

% 5. Gráficos
t = (0:Pasos-1)*Ts;
figure('Color', 'w', 'Position', [100, 50, 800, 700]);
subplot(2,1,1); plot(t, hist_x', 'LineWidth', 2);
title('Velocidades Angulares con Horizonte N=6'); ylabel('rad/s'); grid on;
subplot(2,1,2); plot(t, hist_pwm', 'LineWidth', 1.5);
title('PWM Motores (Estrategia Predictiva)'); ylabel('us'); grid on;