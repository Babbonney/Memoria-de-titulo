clearvars
close all
clc
addpath('./lib_minimal')

%% Modelo
%matriz multi pid
Ad=[  -0.8618   -0.0131   -0.1903;
   -0.0262   -0.9598   -0.0818;
   -0.1390    0.0044   -0.6237];

Bd= [1.8979    0.0281   -0.4399;
   -0.0159   -1.7644   -0.2623;
    0.0655    0.0734    0.4799];

A=Ad;
B=Bd;
n = 3; %largo del vector x
m = 3; %largo del vector u

%% Costos
Q = 10*diag([1 1 1]);
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
% cambiar nombre por slx a utilizar
mw = get_param('mpcmonitorandtune','ModelWorkspace');

mw.assignin('H',H);
mw.assignin('F',F);
mw.assignin('Qvec',Qvec);
mw.assignin('G',G);
mw.assignin('Pc',Pc);
mw.assignin('qc',qc);
mw.assignin('Sc',Sc);
mw.assignin('m',m);
mw.assignin('nu',nu);