clearvars; close all; clc;

%% 1. DEFINICIÓN DEL MODELO (Tus matrices identificadas)
A = [-0.935710267868369,  0.114535661043099,  4.926101069998020;
     -0.003429981478181, -1.040331777969572,  2.779697729794189;
     -0.093493041620156, -0.275240626618720,  1.498523193279717];

B = [-1.904610791203760, -0.587512074882609, -2.268399108168063;
     -0.394955416789158, -1.757390846313468, -1.171599117715514;
     -0.076794484292644, -0.219181465035995, -0.214112941381796];

C = eye(3); 
D = zeros(3);
sys = ss(A, B, C, D);

%% 2. CONFIGURACIÓN DE LA PRUEBA (Modifica estos valores para probar)
t = 0:0.01:5;           % Simulación de 2 segundos
u_roll  = 0.2;          % Comando de Roll deseado (u1)
u_pitch = 0.0;          % Comando de Pitch deseado (u2)
u_yaw   = 0.0;          % Comando de Yaw deseado (u3)
u_hover = 0.35;         % Base de aceleración (Throttle)

% Crear el vector de entrada con un escalón a los 0.2 segundos
U_control = zeros(length(t), 3);
U_control(t > 0.2, 1) = u_roll;
U_control(t > 0.2, 2) = u_pitch;
U_control(t > 0.2, 3) = u_yaw;

%% 3. SIMULACIÓN DE LA DINÁMICA (Salida de Velocidades)
[y_vel, t_out] = lsim(sys, U_control, t);

%% 4. CÁLCULO DE LA REACCIÓN DE LOS MOTORES (Mixer Inverso)
% Basado en la configuración en X de tu código original:
% m1 = th + p + y - r
% m2 = th - p + y + r
% m3 = th + p - y + r
% m4 = th - p - y - r

M = zeros(length(t), 4);
for i = 1:length(t)
    r = U_control(i,1); % Comando Roll
    p = U_control(i,2); % Comando Pitch
    y = U_control(i,3); % Comando Yaw
    th = u_hover;       % Aceleración constante
    
    M(i,1) = th + p + y - r; 
    M(i,2) = th - p + y + r; 
    M(i,3) = th + p - y + r; 
    M(i,4) = th - p - y - r; 
end

%% 5. GRÁFICAS DE REACCIÓN TOTAL
figure('Color', 'w', 'Name', 'Análisis Dinámico: Modelo vs Motores', 'Position', [100 100 800 600]);

% --- Gráfica de Velocidades Angulares (Salida de A y B) ---
subplot(2,1,1);
plot(t_out, y_vel(:,1), 'r', 'LineWidth', 2); hold on;
plot(t_out, y_vel(:,2), 'g', 'LineWidth', 2);
plot(t_out, y_vel(:,3), 'b', 'LineWidth', 2);
grid on; ylabel('Vel. Angular (rad/s)');
legend('p (Roll Rate)', 'q (Pitch Rate)', 'r (Yaw Rate)');
title('Respuesta de las Velocidades (Salida del Modelo A/B)');

% --- Gráfica de los Motores (Entrada del Sistema) ---
subplot(2,1,2);
plot(t_out, M(:,1), 'LineWidth', 1.5); hold on;
plot(t_out, M(:,2), 'LineWidth', 1.5);
plot(t_out, M(:,3), 'LineWidth', 1.5);
plot(t_out, M(:,4), 'LineWidth', 1.5);
yline(u_hover, 'k--', 'Hover (0.35)');
grid on; ylabel('Potencia Motor (0-1)');
xlabel('Tiempo (s)');
legend('M1', 'M2', 'M3', 'M4');
title('Reacción de los Motores para generar ese comando');

%% 6. ANÁLISIS DE ESTABILIDAD
disp('--- Diagnóstico del Sistema ---');
polos = eig(A);
disp('Polos del sistema (Autovalores de A):');
disp(polos);
if any(real(polos) > 0)
    fprintf('AVISO: El sistema es INESTABLE (un polo es positivo).\n');
    fprintf('Las velocidades crecerán exponencialmente.\n');
end