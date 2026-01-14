%% Simulación: Control con Desglose de Motores (Corregido)
clear all; clc;

% 1. Matrices del sistema
A = [      0.9347    0.0728    0.6931;
    0.0043    0.9492    0.1273;
   -0.0283   -0.0333    0.7369];
B = [    0.0094   -0.0779   -0.2379;
   -0.0359    0.1212   -0.0441;
    0.1047    0.0299    0.0955];

n_estados = 3; n_entradas = 3;
Ts = 0.01; Pasos = 150; 
x = [0; 0; 0]; referencia = [0; 0; 0]; 

% 2. Pesos del controlador
Q = eye(n_estados) * 1; 
R = diag([1, 1, 1]); 

options = optimoptions('quadprog', 'Algorithm', 'interior-point-convex', 'Display', 'off');
v_max = 60; lb = -2*ones(3,1); ub = 2*ones(3,1);

% --- MATRIZ DE MEZCLA DEFINITIVA ---
M = [ -1,  1,  1, -1;   % u1
       1, -1,  1, -1;   % u2
       1,  1, -1, -1;   % u3
       1,  1,  1,  1 ]; % u4 (Throttle)

% 3. Inicialización
hist_x = zeros(n_estados, Pasos);
hist_u = zeros(n_entradas, Pasos);
hist_pwm = zeros(4, Pasos); % Cambiamos hist_m por hist_pwm para ver realidad

% 4. Bucle de control
for k = 1:Pasos
    if k == 40, x = x + [0; 15; 0]; end 
    
    hist_x(:, k) = x;
    
    % Optimización
    H = B' * Q * B + R;
    f = B' * Q * (A * x - referencia);
    A_ineq = [B; -B];
    b_ineq = [ones(3,1)*v_max - A*x; ones(3,1)*v_max + A*x];
    
    [u_opt, ~, exitflag] = quadprog(H, f, A_ineq, b_ineq, [], [], lb, ub, [], options);
    u = u_opt;
    if exitflag < 1, u = zeros(3,1); end
    hist_u(:, k) = u;
    
    % --- DESMEZCLA Y CONVERSIÓN A PWM CORRECTA ---
    % u_total incluye u1, u2, u3 y el throttle base (1.4 = 0.35 * 4)
    u_total = [u(1); u(2); u(3); 1.4]; 
    
    % Calculamos m_normalizado mediante la inversa de M
    m_calc = M \ u_total; 
    
    % Convertimos a PWM (1100 a 1900)
    pwm_val = m_calc * 800 + 1100;
    
    % Saturación de seguridad
    pwm_val = max(min(pwm_val, 1900), 1100);
    hist_pwm(:, k) = pwm_val;
    
    % Simulación del sistema
    x = A * x + B * u;
end

% 5. Gráficos
t = (0:Pasos-1)*Ts;
figure('Color', 'w', 'Position', [100, 50, 800, 850]);

subplot(3,1,1); plot(t, hist_x', 'LineWidth', 2);
ylabel('rad/s'); title('Salida: Velocidades Angulares');
legend('Roll', 'Pitch', 'Yaw'); grid on;

subplot(3,1,2); plot(t, hist_u', 'LineWidth', 1.5);
ylabel('Amplitud U'); title('Acciones de Control Combinadas');
legend('u1', 'u2', 'u3'); grid on;

subplot(3,1,3); plot(t, hist_pwm', 'LineWidth', 1.5);
ylabel('PWM (\mu s)'); title('Señales PWM de Motores (Base 1380)');
xlabel('Tiempo (s)'); legend('m1', 'm2', 'm3', 'm4'); grid on;
ylim([1100 1900]);