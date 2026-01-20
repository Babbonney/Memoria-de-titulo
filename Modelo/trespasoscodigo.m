% clearvars
% close all
% clc
% addpath('./lib_minimal')
% 
% %% Modelo
% Ac = [   -1.4099    0.5078    4.2755;
%    -0.4184    0.3873   -0.9443;
%    -0.0965   -0.1478    0.3604];
% Bc = [    6.7816   -1.8615   -2.2590;
%     1.0187    1.7546    0.5642;
%     0.2150    0.3915    0.3528];
% Ts = 0.0201;
% sysc = ss(Ac,Bc,[],[]);
% sysd = c2d(sysc,Ts);
% A=sysd.A;
% B=sysd.B;
% n = 3;
% m=3;
% 
% %% Costos
% Q = diag([1 1 1]);
% R = diag([1 1 1]);
% K = -dlqr(A,B,Q,R);
% 
% %% Restricciones
% U = Polyhedron('lb',-[0.7;0.7;0.7],'ub',[1.3;1.3;1.3]);
% X = Polyhedron('lb',-[1,1,0.3],'ub',[1,1,0.3]);
% 
% %% Ingredientes MPC
% % Horizonte
% N = 5;
% 
% % Costo final (P)
% [P,~,~] = dare(A,B,Q,R);
% 
% % Restriccion final
% sys=LTISystem('A',A+B*K);
% KX=Polyhedron('A',(U.A)*K,'b',U.b);KX.minHRep;KX.minVRep;
% Xaux=intersect(X,KX);Xaux.minHRep;Xaux.minVRep;
% Xf=sys.invariantSet('X',Xaux,'maxIterations',2000);Xf.minHRep;Xf.minVRep;
% 
% 
% % Region de atraccion
% [XN,~,~]=sinfsetMPT(A,B,X,U,Xf,N);
% 
% --- Visualización de conjuntos ---
figure(1);clf;
hold on
plot(X, 'Color', 'blue', 'Alpha', 0.1); 
plot(XN, 'Color', 'green', 'Alpha', 0.3);
plot(Xf, 'Color', 'red', 'Alpha', 0.5);
legend('Restricciones Estado (X)', 'Región Atracción (XN)', 'Conjunto Terminal (Xf)');
title('Análisis de Estabilidad y Factibilidad MPC');
grid on

% Propagar restricciones
% Estas funciones deben existir en tu carpeta ./lib_minimal
[F,G] = predict_mats(A,B,N);
[Pc,qc,Sc] = constraint_mapping(F,G,N,n,X,U,Xf);

%% Funcion costo
Qvec=kron(eye(N-1),Q);
Qvec=blkdiag(Qvec,P);
Rvec=kron(eye(N),R);

H = G'*Qvec*G+Rvec;
u = zeros(m, T);
T = 100;
x0 = [0.4;0.2;0.1];
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
