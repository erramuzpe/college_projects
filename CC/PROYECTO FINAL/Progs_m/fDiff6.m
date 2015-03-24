function fDiff6
% Finite difference method for the second-order,
% linear boundary value problem in Example 8.6.

xStart = 0; xStop = pi/2;   % Range of integration.
n = 11;                     % Number of mesh points.
freq = 1;                   % Printout frequency.

h = (xStop - xStart)/(n-1);
x = linspace(xStart,xStop,n)';
[c,d,e,b] = fDiffEqs(x,h,n);
[c,d,e] = LUdec3(c,d,e);
printSol(x,LUsol3(c,d,e,b),freq)
    
function [c,d,e,b] = fDiffEqs(x,h,n)
% Sets up the tridiagonal coefficient matrix and the
% constant vector of the finite difference equations.
h2 = h*h;
d = ones(n,1)*(-2 + 4*h2);
c = ones(n-1,1);
e = ones(n-1,1);
b = ones(n,1)*4*h2.*x;
d(1) = 1; e(1) = 0; b(1) = 0;c(n-1) = 2;
