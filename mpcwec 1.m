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

% %% Simulacion control LQR
% x(:,1) = randn(2,1);
% 
% T = 100;
% for i=1:100
%     u(:,i) = Klqr*x(:,i);
%     x(:,i+1) = A*x(:,i) + B*u(:,i);
% end

%% Restricciones
X = Polyhedron('lb',-[1;2],'ub',[1;2]);
U = Polyhedron('lb',-1000,'ub',1000);
% plot(X,'Color','Blue','Alpha',0.5)
% plot(U,'Color','Blue','Alpha',0.5)

%% Ingredientes MPC
% Horizonte
N = 3;

% Costo final
[P,~,~] = dare(A,B,Q,R);

% Restriccion final
% Xf = 0.1*X;
sys=LTISystem('A',A+B*K);
KX=Polyhedron('A',(U.A)*K,'b',U.b);KX.minHRep;KX.minVRep;
Xaux=intersect(X,KX);Xaux.minHRep;Xaux.minVRep;
Xf=sys.invariantSet('X',Xaux,'maxIterations',2000);Xf.minHRep;Xf.minVRep;

% Region de atraccion
[XN,~,~]=sinfsetMPT(A,B,X,U,Xf,N);

% hold on
% plot(X,'Color','Blue','Alpha',0.5)
% plot(XN,'Color','Green','Alpha',0.5)
% plot(Xf,'Color','Red','Alpha',0.5)

%% Propagar restricciones
[F,G] = predict_mats(A,B,N);
[Pc,qc,Sc] = constraint_mapping(F,G,N,n,X,U,Xf);

% x0 = [0.4;1.5];
% Ufactible = Polyhedron('A',Pc,'b',qc+Sc*x0);
% plot(Ufactible,'Color','Blue','Alpha',0.5)


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
    u(:,i) = uvec(1);
    x(:,i+1) = A*x(:,i) + B*u(:,i);
end


