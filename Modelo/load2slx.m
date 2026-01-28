clearvars
close all
clc
addpath('./lib_minimal')

%% Modelo
% Ad = [   -1.4099    0.5078    4.2755;
%    -0.4184    0.3873   -0.9443;
%    -0.0965   -0.1478    0.3604];
% Bd = [    6.7816   -1.8615   -2.2590;
%     1.0187    1.7546    0.5642;
%     0.2150    0.3915    0.3528];
% matriz con pattern search
% Ad = [-1.1990   -0.2847   -1.2180;
%    -0.0272    0.5988   -0.4729;
%     0.1652    0.0000    0.0504];
% Bd = [    5.8998    0.6530    0.7290;
%    -0.0000    1.1668    0.2982;
%    -0.4883    0.0415    0.5172];
% matriz lsqunonlin
% Ad =   [   -0.7523   -0.4866    1.5629;
%     0.2716   -1.5547    1.8027;
%    -0.2439   -0.1860    0.1810];
% Bd = [    4.2973   -0.9311   -1.2273;
%     0.0717   -5.4300   -0.9758;
%     0.4726   -0.3790    0.5890];
%matriz fmincon
% Ad =   [-0.7032   -0.5711    1.7669;
%     0.2778   -1.4711    1.3647;
%    -0.2558   -0.0480   -0.0580];
% Bd = [4.2242   -1.1144   -1.3646;
%    -0.0110   -5.2505   -0.6752;
%     0.4464   -0.0899    0.7457];
%matriz multi pid
Ad=[  -0.8618   -0.0131   -0.1903;
   -0.0262   -0.9598   -0.0818;
   -0.1390    0.0044   -0.6237];

Bd= [1.8979    0.0281   -0.4399;
   -0.0159   -1.7644   -0.2623;
    0.0655    0.0734    0.4799];
% Estimada sin los sqrt(2)/2
% Bd = [4.7953   -1.3163   -2.2590;
%     0.7204    1.2407    0.5642;
%     0.1520    0.2768    0.3528];
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

mw = get_param('mpcprueba3','ModelWorkspace');

mw.assignin('H',H);
mw.assignin('F',F);
mw.assignin('Qvec',Qvec);
mw.assignin('G',G);
mw.assignin('Pc',Pc);
mw.assignin('qc',qc);
mw.assignin('Sc',Sc);
mw.assignin('m',m);
mw.assignin('nu',nu);