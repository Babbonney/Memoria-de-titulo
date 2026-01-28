clearvars;
clc;
close all;
% cargar datos
d_motores = readtable('datos_finales.xlsx');
u = [d_motores.U1_Roll,d_motores.U2_Pitch,d_motores.U3_Yaw];
y= [d_motores.Y1_RollRate,d_motores.Y2_PitchRate,d_motores.Y3_YawRate];
Ts = (d_motores.Tiempo(2)-d_motores.Tiempo(1));
data_tr = iddata(y(1:floor(0.7*end), :), u(1:floor(0.7*end), :), Ts);
data_va = iddata(y(floor(0.7*end)+1:end, :), u(floor(0.7*end)+1:end, :), Ts);

% Definir estructura base de Espacio de Estados
m_base = idss(zeros(3), zeros(3), eye(3), zeros(3), zeros(3), 'Ts', Ts);
S = m_base.Structure;
S.C.Free = false; 
S.D.Free = false; 
S.K.Free = false; 
m_base.Structure = S;

% Configuración del algoritmo de identificación
opt = ssestOptions;
opt.InitializeMethod = 'n4sid';
opt.InitialState = 'estimate';
opt.Focus = 'simulation';  
opt.EnforceStability = false;
opt.SearchMethod = 'lm'; 

% Estimación
mm = ssest(data_tr, m_base, opt);
s_lo = pem(data_tr, mm, opt); % Refinamiento final

%% 6. VALIDACIÓN Y GRÁFICOS
optc = compareOptions('InitialCondition', 'estimate');
figure('Name', 'Validación del Modelo', 'Color', 'w');
compare(data_va, s_lo, optc);

% Mostrar Matrices Finales para el MPC
disp('--- MATRICES IDENTIFICADAS ---');
fprintf('Matriz A:\n'); disp(s_lo.A);
fprintf('Matriz B:\n'); disp(s_lo.B);

s_lo.Report.Fit.FitPercent