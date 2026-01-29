clearvars
close all
clc
addpath('./lib_minimal')

%% Modelo
Ad=    [ 1.0101         0         0;
         0    1.0101         0;
         0         0    1.0101];
Bd=[    0.3357         0         0;
         0    0.9698         0;
         0         0    0.0305];

A=Ad;
B=Bd;
n = 3; %largo del vector x
m = 3; %largo del vector u

%% Costos
Q = diag([1 1 1]);
R = diag([3 3 3]);
K = -dlqr(A,B,Q,R);

%% Restricciones
U = Polyhedron('lb',-[sqrt(2);sqrt(2);2],'ub',[sqrt(2);sqrt(2);2]);
X = Polyhedron('lb',-[1,1,1],'ub',[1,1,1]);

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
nu= size(H,1);
% Cargar parametros a simulink

mw = get_param('mpc5','ModelWorkspace');

mw.assignin('H',H);
mw.assignin('F',F);
mw.assignin('Qvec',Qvec);
mw.assignin('G',G);
mw.assignin('Pc',Pc);
mw.assignin('qc',qc);
mw.assignin('Sc',Sc);
mw.assignin('m',m);
mw.assignin('nu',nu);