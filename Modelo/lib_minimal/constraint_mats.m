function [Pc, qc, Sc] = constraint_mats(F,G,umin,umax,xmin,xmax)

% input dimension
m = length(umin);
n = size(F,2);
N = size(F,1)/n;

% Build the input constraints
Iu = kron(ones(N,1),eye(m));

% input constraint rows of Pc and qc
Pcu = [eye(m*N); -eye(m*N)];
qcu = [Iu*umax; -Iu*umin];
Scu = zeros(size(qcu,1),n);

if ~isempty(xmin)
  % Build the state constraints
  Ix = kron(ones(N,1),eye(n));
  
  % state constraint rows of Pc and qc
  Pcx = [eye(n*N); -eye(n*N)]*G;
  qcx = [Ix*xmax; -Ix*xmin];
  Scx = -[eye(n*N); -eye(n*N)]*F;
else
    Pcx = [];
    qcx = [];
    Scx = [];
end

Pc = [Pcu; Pcx];
qc = [qcu; qcx];
Sc = [Scu; Scx];
