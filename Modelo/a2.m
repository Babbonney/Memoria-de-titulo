clear all; clc; close all;

% 1. Matrices del sistema
% A = [1.411918576919691	-0.693561448505833	4.375097256720057;
% 1.654408978801020	-0.970695784162933	4.495703731601560;
% 1.184646637411131	-1.201738969584671	-0.441973665602317];
% B = [-1.785500908606258	-1.002708556358094	-1.536176694083594;
% -1.932636405573473	-1.558039864385865	-1.251645050120990;
% 0.528635023317011	-0.218728316211266	0.869717674155508];
A =  [   -2.0133    0.8978    6.7850;
   -0.4614    0.4367   -0.6621;
   -0.0833   -0.1459    0.3591];  
B = [    6.0807   -2.2374   -3.6142;
    0.8163    1.1287    0.4113;
    0.1286    0.2742    0.3532];


n_estados = 3; n_entradas = 3;
Ts = 0.01; Pasos = 1000; 
N = 12; % <--- NUEVO: Horizonte de predicción

x = [0; 0; 0]; referencia = [0; 0; 0]; 

% 2. Pesos del controlador (Mantenemos tus valores equilibrados)
Q_inst = eye(n_estados) * 1; 
R_inst = diag([1 1 1]); 

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
    if k == 40, x = x + [1;0 ; 0]; end 
    
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