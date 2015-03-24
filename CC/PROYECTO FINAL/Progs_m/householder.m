function A = householder(A)
% Housholder reduction of A to tridiagonal form A = [c\d\c].
% Extract c and d with d = diag(A), c = diag(A,1).
% USAGE: A = householder(A).

n = size(A,1);
for k = 1:n-2
    u = A(k+1:n,k);
    uMag = sqrt(dot(u,u));
    if u(1) < 0; uMag = -uMag; end
    u(1) = u(1) + uMag;
    A(k+1:n,k) = u;            % Save u in lower part of A
    H = dot(u,u)/2;
    v = A(k+1:n,k+1:n)*u/H;
    g = dot(u,v)/(2*H);
    v = v - g*u;
    A(k+1:n,k+1:n) = A(k+1:n,k+1:n) - v*u' - u*v';
    A(k,k+1) = -uMag;
end
   