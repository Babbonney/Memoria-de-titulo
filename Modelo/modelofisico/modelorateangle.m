clc, clearvars, close all;addpath('C:\Users\aero\Desktop\Proyecto control AMPC-DMPC\repositorios\Memoria-de-titulo\Modelo\lib_minimal');
%Modelo Fisico
m= 3; % kg estimados
lx= 0.47/2; % brazo roll
ly= 0.33/2; % brazo pitch
mt= (800-600)/(6360-5500); %pendiente thrust rango pequeno
thrustequilibro = 3000/4; %gf aproximadamente 6000 rpm
uhover= mean(0.1344 + 0.2078 + 0.1551 + 0.2548); %promedio esc
%supongamos que si aumento u en 0.17 aumenta 1000 rpm
deltaT= mt*1000;
ku= (deltaT/0.17)* 0.00980664; %en newtons relacion de cuanto aumenta thrust si aumento u en peque;os valores
%roll
taux = ly*ku;

%pitch
tauy = lx*ku;
% yaw se escoje un valor arbitrario [0.2,0.4]
tauz= 0.3;

%centro de masas centro igual 1.8 y motores 0.3 cada uno
jx= 4 * (0.1*m) * (lx^2);
jy= 4 * (0.1*m) * (ly^2);
jz= 4 * (0.1*m) * ((lx^2)+(ly^2));

%dinamica rotacional
p = taux/jx;
q = tauy/jy;
r = tauz/jz;

x = [0 0 0 ; 0 0 0; 1/jx 0 0; 0 1/jy 0; 0 0 1/jz];
Ac =  [ 0 0  1 0 0;
       0 0  0 1 0;
       0 0  0 0 0;
       0 0  0 0 0;
       0 0  0 0 0 ];
Bc = x;
Ts = 0.1;
sysc = ss(Ac,Bc,eye(5),zeros(5,3));
sysd = c2d(sysc,Ts);
A=sysd.A;
B=sysd.B;
n = 5; %largo del vector x
m = 3; %largo del vector u

%% Costos
Q = 1*diag([0.2 0.2 8 8 3]);
R = diag([0.8 0.8 1.5]);
K = -dlqr(A,B,Q,R);

%% Restricciones
U = Polyhedron('lb',-[sqrt(2);sqrt(2);2],'ub',[sqrt(2);sqrt(2);2]);
% X = Polyhedron('lb',-[3,3,1.5],'ub',[3,3,1.5]);
X = Polyhedron('lb',-[1,1,1,1,0.5],'ub',[1,1,1,1,0.5]);

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
tol= 1e-3;
[XN,~,~]=sinfsetMPT(A,B,X,U,Xf,N);%,[],tol);

%--- Visualizacion de conjuntos ---
figure(1); clf; hold on;

Xp  = X.projection([1 2]);
XNp = XN.projection([1 2]);
Xfp = Xf.projection([1 2]);
Up_xy = U.projection([1 2]);

plot(Xp,  'Color','blue',  'Alpha',0.1);
plot(XNp, 'Color','green', 'Alpha',0.3);
plot(Xfp, 'Color','red',   'Alpha',0.5);

legend('X','XN','Xf');
xlabel('\phi'); ylabel('\theta');
grid on
Xp_3d  = X.projection([1 2 5]);
XNp_3d = XN.projection([1 2 5]);
Xfp_3d = Xf.projection([1 2 5]);
figure(2); hold on

plot(Xp_3d,  'Color','blue',  'Alpha',0.05)
plot(XNp_3d, 'Color','green', 'Alpha',0.25)
plot(Xfp_3d, 'Color','red',   'Alpha',0.4)

xlabel('\phi [rad]')
ylabel('\theta [rad]')
zlabel('r [rad/s]')
grid on
view(135,25)

legend('X','XN','Xf')

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
x0 = [0;0;-1.5;2;-1];
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
t = (0:T-1)*Ts;
figure(1); hold on
plot(Up_xy, 'Color','blue', 'Alpha',0.1)

plot(u(1,:), u(2,:), 'r', 'LineWidth',2)
plot(u(1,1), u(2,1), 'ks','MarkerFaceColor','k')

xlabel('\tau_x')
ylabel('\tau_y')
grid on
legend('U','trayectoria u')

figure(2); hold on
plot3(x(1,:), x(2,:), x(5,:), 'k','LineWidth',2)
plot3(x(1,1), x(2,1), x(5,1), 'ks','MarkerFaceColor','k')

xlabel('\phi [rad]')
ylabel('\theta [rad]')
zlabel('r [rad/s]')
grid on
view(135,25)
figure(3);
subplot(3,1,1)
plot(t, u(1,:), 'LineWidth',1.5)
ylabel('\tau_x')
grid on

subplot(3,1,2)
plot(t, u(2,:), 'LineWidth',1.5)
ylabel('\tau_y')
grid on

subplot(3,1,3)
plot(t, u(3,:), 'LineWidth',1.5)
ylabel('\tau_z')
xlabel('Tiempo [s]')
grid on

