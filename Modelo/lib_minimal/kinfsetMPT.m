function [Kinf,tstar,fd] = kinfsetMPT(A,B,E,X,U,W,T,tmax,lambda,tol)
% KINFSET Calculates robust lambda-contractive controllable sets for 
%           a discrete-time LTI system, subject to polytopic uncertainty 
%           and state disturbances
%
%   Usage:
%     [Kinf,tstar,fd] = kinfset(A,B,E,X,U,W,T,tmax,lambda,tol)
%
%   Inputs:
%      A,B,E:  The A and B matrices of the system 
%                x_{k+1} = Ax_k + Bu_k + Ew_k.
%              For polytopic uncertainty, stack vertices 
%              of uncertainty sets for A and B on top of each other.
%      X:      State constraints in polyhedron form (MPT toolbox).
%      U:      Control constraints in polyhedron form (MPT toolbox).
%      W:      Disturbance set in polyhedron form (MPT toolbox).
%      T:      Target set in polyhedron form (MPT toolbox).
%                Default is X for computing the maximal lambda-contractive
%                  (robust control invariant) set.
%      tmax:   Maximum number of iterations.
%      lambda: (optional) Contraction factor 0 < lambda <= 1 (default 1).
%      tol:    (optional) Tolerance for stopping criteria (default []).
%              If T == X, then allowed range is 0 <= tol < 1-lambda.
%                If tol >= 0, then stops when set is (lambda+tol)-contractive.
%                If tol == [], then ISEQUALSETS is used to check for
%                  finite determinedness.
%              If T ~= X, then allowed range is tol >= 0 and ISEQUALSETS
%                  is used to check for finite determinedness.
%
%   Outputs:
%     Kinf:  Lambda-contractive set contained in X.
%              If T == X, then Kinf is a (lambda+tol)-contractive inner
%                approximation of the maximal lambda-contractive 
%                (robust control invariant) set contained in X.
%              If T ~= X and T is lambda-contractive (robust control invariant),
%                then Kinf is a lambda-contractive inner approximation of
%                the maximal lambda-contractive stabilisable set to T.
%     tstar: Determinedness index.
%     fd:    0 if tstar > tmax.
%            1 if Kinf is finitely determined (tstar <= tmax). 
%            2 if Kinf is empty.
%            3 if the origin is not in the interior of Kinf (not a C-set).
%
%   See also AUG2STD, STD2AUG, K1SET, CINFSET, SINFSET, OINFSET, OINFDIST
%
% Invariant Set Toolbox
% Version 0.10.2, Date: 20/7/2001
% Copyright (c) by Eric Kerrigan

if isempty(T)
  T = X;
  TandXequal = 1;
else
  TandXequal = T.eq(X);
end

if nargin >= 9
  if isempty(lambda)
     lambda = 1;
  end
else
  lambda = 1;
end

if nargin <= 9
  tol = [];
end

[rA,cA] = size(A);

if rA == cA % If no uncertainty in (A,B)
  [n,m]=size(A);
  U=U.affineMap(B);
  B = eye(n);
end

t = 1;
fd = 0;
D0 = T;

while t <= tmax && fd == 0
  disp(sprintf('\n*Calculating controllable sets: Step %d of %d\n',t,tmax))

%   A
%   B
%   E
%   X.H
%   U.H
%   [U.Ae U.be]
%   W.H
%   [W.Ae W.be]
%   D0.H
%   lambda
%   if t==1
%       save('mpt','A','B','E','X','U','W','D0','lambda')
%   end
  
  D1 = k1setMPT(A,B,X,U,D0,1,lambda,E,W);
%   save('mpt','D1')
%   plot(D1,'Marker','*','Alpha',0)
									   
  if ~isempty(W) && (fd == 0)
    if D1.isEmptySet
		  fd = 2;
		  D1 = [];
		  warning('**THE NEW SET IS EMPTY**')
    else
      if ~D1.isInside(zeros(n,1)) % if not a C-set
		fd = 3;
		warning('**THE ORIGIN IS NOT IN THE INTERIOR OF THE NEW SET**')
	  end
	end
  end
				
  if fd == 0
  if TandXequal                  % if computing maximal lambda-contractive set
	if isempty(tol)              % and tol is not given
	  fd = D0.eq(D1);            % then check whether sets are equal
	  if fd == 1
	    t = t - 1;
	  end
	else                         % else check whether set is (lambda+tol)-contractive
	  fd = isrobctrlinvMPT(A,B,D1,U,E,W,min(lambda+tol,1)); % See Blanchini
	                             % IEEE TAC Vol 39:2, pp. 428-433, 1994, Theorem 3.2
	end
  else                           % if not computing maximal lambda-contractive set
	if isempty(tol)              % then check whether equal within given tolerance
        tol = eps;
    end
    tolD0=(1+tol)*D0;            
    
    tolD1=(1+tol)*D1;
    fd = tolD0.contains(D1) & tolD1.contains(D0);
	if fd == 1
	  t = t - 1;
	end
  end
  end
  
% if ~isempty(D1) & isillcon(D1)
%	if is0inint(D1)
%	  D1 = normalise(D1);
%	  warning('*Normalising - entries for polyhedron ill-conditioned*')
%	end
%  end
  
  D0 = D1;
  t = t + 1; 
end

Kinf = D1;
tstar = t - 1;
