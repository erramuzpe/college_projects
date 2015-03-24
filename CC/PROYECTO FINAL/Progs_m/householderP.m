function P = householderP(A)
% Computes transformation matrix P after 
% Householder reduction of A is carried out.
% USAGE: P = householderP(A).

n = size(A,1);
P = eye(n);
for k = 1:n-2
    u = A(k+1:n,k);
    H = dot(u,u)/2;
    v = P(1:n,k+1:n)*u/H;
    P(1:n,k+1:n) = P(1:n,k+1:n) - v*u';
end
