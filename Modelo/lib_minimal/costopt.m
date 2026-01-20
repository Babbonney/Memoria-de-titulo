function J = costopt(optva,Q,R,A,B,N,n,m,x)
% Unpacking of optimization variable
upred = optva;

% Prediction
[F,G] = predict_mats(A,B,N);
xpred=F*x+G*upred;
xpred=[x;xpred];
xpred = reshape(xpred,n,N+1);
upred = reshape(upred,m,N);

% Cost function
J = 0;
for i=1:length(upred)-1
    J = J + xpred(:,i)'*Q*xpred(:,i) + upred(:,i)'*R*upred(:,i);
end

end