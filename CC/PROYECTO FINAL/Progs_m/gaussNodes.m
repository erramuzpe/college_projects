function [x,A] = gaussNodes(n,tol)
% Computes nodal abscissas x and weights A of
% Gauss-Legendre n-point quadrature.
% USAGE: [x,A] = gaussNodes(n,epsilon,maxIter)
% tol = error tolerance (default is 1.0e4*eps).

if nargin < 2; tol = 1.0e4*eps; end
A = zeros(n,1); x = zeros(n,1);
nRoots = fix(n + 1)/2;                % Number of non-neg. roots
for i = 1:nRoots
    t = cos(pi*(i - 0.25)/(n + 0.5)); % Approx. roots
    for j = i:30
        [p,dp] = legendre(t,n);       % Newton's
        dt = -p/dp; t = t + dt;       % root finding
        if abs(dt) < tol              % method  
            x(i) = t; x(n-i+1) = -t;
            A(i) = 2/(1-t^2)/dp^2;    % Eq. (6.25)
            A(n-i+1) = A(i);
            break
        end
    end
end    

function [p,dp] = legendre(t,n)
% Evaluates Legendre polynomial p of degree n 
% and its derivative dp at x = t.
p0 = 1.0; p1 = t;
for k = 1:n-1
    p = ((2*k + 1)*t*p1 - k*p0)/(k + 1); % Eq. (6.19)
    p0 = p1;p1 = p;
end
dp = n *(p0 - t*p1)/(1 - t^2);           % Eq. (6.21)
