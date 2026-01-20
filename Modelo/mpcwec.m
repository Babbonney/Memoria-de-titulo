clearvars
close all
clc
addpath('./lib_minimal')

%% Modelo
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
m=1;

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

% Restriccion final
sys=LTISystem('A',A+B*K);
KX=Polyhedron('A',(U.A)*K,'b',U.b);KX.minHRep;KX.minVRep;
Xaux=intersect(X,KX);Xaux.minHRep;Xaux.minVRep;
Xf=sys.invariantSet('X',Xaux,'maxIterations',2000);Xf.minHRep;Xf.minVRep;

% Region de atraccion
[XN,~,~]=sinfsetMPT(A,B,X,U,Xf,N);

% --- Visualización de conjuntos ---
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

H = G'*Qvec*G+Rvec;

T = 100;
x0 = [0.4;1.5];
x(:,1) = x0;
for i = 1:T
    f = (2*x(:,i)'*F'*Qvec*G)';
    uvec = quadprog(2*H,f,Pc,qc+Sc*x(:,i));
    u(:,i) = uvec(1:m);
    x(:,i+1) = A*x(:,i) + B*u(:,i);
end

figure(1);
hold on
plot(x(1,:),x(2,:),'k','LineWidth',2); 
plot(x(1,1),x(2,1),'ks'); 
