clearvars
close all
clc
addpath('./lib_minimal')

%% Modelo
m = 10;
k = 1000;
c = 50;
Ac = [0 1;-k/m -c/m];
Bc = [0;1];
Ts = 0.1;
sysc = ss(Ac,Bc,[],[]);
sysd = c2d(sysc,Ts);
A=sysd.A;
B=sysd.B;
n = 2;

%% Costos
Q = [1 0;0 2];
R = 3;
K = -dlqr(A,B,Q,R);

%% Restricciones
X = Polyhedron('lb',-[1;2],'ub',[1;2]);
U = Polyhedron('lb',-1000,'ub',1000);

%% Ingredientes MPC
% Horizonte
N = 3;

% Costo final (P)
[P,~,~] = dare(A,B,Q,R);

% --- Cálculo de la Restriccion final (Xf) usando MPT3 ---
sys_cl = LTISystem('A', A + B*K); 
% KX representa el conjunto de estados donde u=Kx cumple con las restricciones de entrada
KX = Polyhedron('A', U.A * K, 'b', U.b); 
Xaux = X & KX; % Intersección de restricciones de estado y entrada
Xf = sys_cl.invariantSet('X', Xaux); 
Xf.minHRep();

% --- Cálculo de la Región de Atracción (Sustituto de sinfsetMPT) ---
model = LTISystem('A', A, 'B', B);
model.x.with('setConstraint');
model.x.set = X; 
model.u.with('setConstraint');
model.u.set = U;

% Calculamos XN: estados que pueden llegar a Xf en N pasos cumpliendo X y U
XN = model.reachset(N, 'direction', 'backward', 'target', Xf);
XN.minHRep();

% --- Visualización de conjuntos ---
figure;
hold on
plot(X, 'Color', 'blue', 'Alpha', 0.1); 
plot(XN, 'Color', 'green', 'Alpha', 0.3);
plot(Xf, 'Color', 'red', 'Alpha', 0.5);
legend('Restricciones Estado (X)', 'Región Atracción (XN)', 'Conjunto Terminal (Xf)');
title('Análisis de Estabilidad y Factibilidad MPC');
grid on

%% Propagar restricciones
% Estas funciones deben existir en tu carpeta ./lib_minimal
[F,G] = predict_mats(A,B,N);
[Pc,qc,Sc] = constraint_mapping(F,G,N,n,X,U,Xf);

%% Simulación (Bucle de Control)
T_sim = 100;
x0 = [0.4;1.5];
x = zeros(n, T_sim+1);
u = zeros(1, T_sim);
x(:,1) = x0;

% Configuración de quadprog para velocidad
opts =  optimset('Display','off');

for i = 1:T_sim
    % Funcion costo: J = u'Hu + f'u
    H = G'*kron(eye(N-1),Q)*G + G'*blkdiag(zeros(n*(N-1)),P)*G + kron(eye(N),R);
    f = (2*x(:,i)'*F'*(blkdiag(kron(eye(N-1),Q),P))*G)';
    
    % Resolver QP
    [uvec, ~, exitflag] = quadprog(2*H, f, Pc, qc + Sc*x(:,i), [], [], [], [], [], opts);
    
    if exitflag ~= 1
        warning('Problema de optimización no factible en paso %d', i);
        break;
    end
    
    u(:,i) = uvec(1);
    x(:,i+1) = A*x(:,i) + B*u(:,i);
end

%% Graficar resultados de simulación
figure;
subplot(2,1,1);
plot(x'); title('Estados'); legend('Posición','Velocidad'); grid on
subplot(2,1,2);
stairs(u); title('Acción de Control (u)'); grid on