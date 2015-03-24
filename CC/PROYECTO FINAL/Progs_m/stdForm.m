function [H,T] = stdForm(A,B)
% Transforms A*x = lambda*B*x to H*z = lambda*z
% and computes transformation matrix T in x = T*z.
% USAGE: [H,T] = stdForm(A,B)

n = size(A,1);
L = choleski(B); Linv = invert(L);
H = Linv*(A*Linv'); T = Linv';

function Linv = invert(L)
% Inverts lower triangular matrix L.
n = size(L,1);
for j = 1:n-1
    L(j,j) = 1/L(j,j);
    for i = j+1:n
        L(i,j) = -dot(L(i,j:i-1), L(j:i-1,j)/L(i,i));
    end 
end
L(n,n) = 1/L(n,n); Linv = L;