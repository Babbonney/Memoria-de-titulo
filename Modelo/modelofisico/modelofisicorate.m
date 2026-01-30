clc, clearvars, close all;
%Modelo Fisico
masa= 3; % kg estimados
lx= 0.47/2; % brazo roll
ly= 0.33/2; % brazo pitch
mt= (800-600)/(6360-5500); %pendiente thrust rango pequeno
thrustequilibro = 3000/4; %gf aproximadamente 6000 rpm
uhover= mean(0.1344 + 0.2078 + 0.1551 + 0.2548); %promedio esc
%supongamos que si aumento u en 0.17 aumenta 1000 rpm
deltaT= mt*1000;
ku= (deltaT/0.17)* 0.00980664; %en newtons relacion de cuanto aumenta thrust si aumento u en peque;os valores
%roll
taux = lx*ku;

%pitch
tauy = ly*ku;
% yaw se escoje un valor arbitrario [0.2,0.4]
tauz= 0.3;

%centro de masas centro igual 1.8 y motores 0.3 cada uno
jx= 4 * (0.1*masa) * (lx^2);
jy= 4 * (0.1*masa) * (ly^2);
jz= 4 * (0.1*masa) * ((lx^2)+(ly^2));

%dinamica rotacional
p = taux/jx;
q = tauy/jy;
r = tauz/jz;

x = [p 0 0; 0 q 0; 0 0 r];
Ac = eye(3);
Bc = x;
Ts = 0.01;
sysc = ss(Ac,Bc,[],[]);
sysd = c2d(sysc,Ts);
A=sysd.A;
B=sysd.B;
n = 3; %largo del vector x
m = 3; %largo del vector u

%% Costos
Q = diag([1 1 1]);
R = diag([1 1 1]);
K = -dlqr(A,B,Q,R);

%% Restricciones
U = Polyhedron('lb',-[sqrt(2);sqrt(2);2],'ub',[sqrt(2);sqrt(2);2]);
% X = Polyhedron('lb',-[3,3,1.5],'ub',[3,3,1.5]);
X = Polyhedron('lb',-[1,1,0.5],'ub',[1,1,0.5]);

%% Ingredientes MPC
% Horizonte
N = 5;

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
x0 = [1;0;0];
x(:,1) = x0;

% opt = optimoptions('quadprog');
% opt.MaxIterations=10;
% opt.Display='iter-detailed';

for i = 1:T
    f = (2*x(:,i)'*F'*Qvec*G)';
    [uvec,a,b] = quadprog(2*H,f,Pc,qc+Sc*x(:,i),[],[],[],[],[],[]);
    % if flag >0
    u(:,i) = uvec(1:m);
    u_prev = u(:,i);
    % elsef
    % u(:,i) = u_prev;
    % end
    x(:,i+1) = A*x(:,i) + B*u(:,i);
end

figure(1);
hold on
plot3(x(1,:),x(2,:),x(3,:),'k','LineWidth',2); 
plot3(x(1,1),x(2,1),x(3,1),'ks'); 




