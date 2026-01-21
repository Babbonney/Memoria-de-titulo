clearvars
close all
clc
addpath('./lib_minimal')

%% Modelo
Ad = [   -1.4099    0.5078    4.2755;
   -0.4184    0.3873   -0.9443;
   -0.0965   -0.1478    0.3604];
Bd = [    6.7816   -1.8615   -2.2590;
    1.0187    1.7546    0.5642;
    0.2150    0.3915    0.3528];
% Estimada sin los sqrt(2)/2
% Bd = [4.7953   -1.3163   -2.2590;
%     0.7204    1.2407    0.5642;
%     0.1520    0.2768    0.3528];

Ts = 0.0201;
A=Ad;
B=Bd;
n = 3; %largo del vector x
m = 3; %largo del vector u

%% Costos
Q = 1000*diag([5 5 8]);
R = diag([40 40 40]);
K = -dlqr(A,B,Q,R);

%% Restricciones
U = Polyhedron('lb',-[sqrt(2);sqrt(2);2],'ub',[sqrt(2);sqrt(2);2]);
X = Polyhedron('lb',-[3,3,1.5],'ub',[3,3,1.5]);

%% Ingredientes MPC
% Horizonte
N = 2;

% Costo final (P)
[P,~,~] = dare(A,B,Q,R);
% Restriccion final
sys=LTISystem('A',A+B*K);
KX=Polyhedron('A',(U.A)*K,'b',U.b);KX.minHRep;KX.minVRep;
Xaux=intersect(X,KX);Xaux.minHRep;Xaux.minVRep;
Xf=sys.invariantSet('X',Xaux,'maxIterations',2000);Xf.minHRep;Xf.minVRep;

% Region de atraccion
tol= 1e-3;
[XN,~,~]=sinfsetMPT(A,B,X,U,Xf,N);%,[],tol);

%--- Visualizacion de conjuntos ---
figure(1);clf;
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

%% Funcion costo
Qvec=kron(eye(N-1),Q);
Qvec=blkdiag(Qvec,P);
Rvec=kron(eye(N),R);
T = 100;

H = G'*Qvec*G+Rvec;
H = (H+H')/2;
u = zeros(m, T);
x0 = 10*[5;5;5];
x(:,1) = x0;

% opt = optimoptions('quadprog');
% opt.MaxIterations=10;
% opt.Display='iter-detailed';

for i = 1:T
    f = (2*x(:,i)'*F'*Qvec*G)';
    [uvec,func,flag] = quadprog(2*H,f,Pc,qc+Sc*x(:,i),[],[],[],[],[],[]);
    u(:,i) = uvec(1:m);
    x(:,i+1) = A*x(:,i) + B*u(:,i);
end

figure(1);
hold on
plot3(x(1,:),x(2,:),x(3,:),'k','LineWidth',2); 
plot3(x(1,1),x(2,1),x(3,1),'ks'); 
