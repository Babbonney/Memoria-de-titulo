function [S,j,R] = RPI_set_bf(W,A,B,K,ite)

Ak=A+B*K;
j=1;
R{j}=W;
while j > 0
    j=j+1;
    add=W.affineMap((Ak^(j-1)));add.minHRep;add.minVRep;
    R{j}=plus(R{j-1},add);R{j}.minHRep;R{j}.minVRep;
    if R{j}.eq(R{j-1}) == 1
        break
    elseif j>=ite
        break
    end
    clear add
end
S=R{j};
close