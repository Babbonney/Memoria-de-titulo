function [Pc,qc,Sc] = constraint_mapping(F,G,N,n,X,U,Xf)

% Mapping of state constraints into input constraints through the horizon
Px=X.A;qxh=X.b;
Pcx=kron(eye(N),Px)*G;
qcx=repmat(qxh,N,1);
Scx=-kron(eye(N),Px)*F;

% Mapping of input constraints through the horizon
Pu=U.A;quh=U.b;
Pcu=kron(eye(N),Pu);
qcu=repmat(quh,N,1);
Scu=-zeros(length(qcu),n);

% Mapping of terminal constraints into input constraints through the horizon
Pxf=Xf.A;qxhf=Xf.b;
Pcxf=Pxf*G((N-1)*n+1:N*n,:);
qcxf=qxhf;
Scxf=-Pxf*F((N-1)*n+1:N*n,:);

% Final constraints (Pu <= q + Sx) where v is the input sequence throughout
% the horizon and x is the current initial state.
Pc=[Pcx;Pcu;Pcxf];
qc=[qcx;qcu;qcxf];
Sc=[Scx;Scu;Scxf];

end