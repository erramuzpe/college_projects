function fDiff8
% Finite difference method for the 4th-order,
% linear boundary value problem in Example 8.8.

xStart = 0; xStop = 0.5;  % Range of integration.
n = 21;                   % Number of mesh points.
freq = 1;                 % Printout frequency.
h = (xStop - xStart)/(n-1);
x = linspace(xStart,xStop,n)';
[d,e,f,b] = fDiffEqs(x,h,n);
[d,e,f] = LUdec5(d,e,f);
printSol(x,LUsol5(d,e,f,b),freq)

function [d,e,f,b] = fDiffEqs(x,h,n)
% Sets up the pentadiagonal coefficient matrix and the
% constant vector of the finite difference equations.
d = ones(n,1)*6;
e = ones(n-1,1)*(-4);
f = ones(n-2,1);
b = zeros(n,1);
d(1) = 1; d(2) = 7; d(n-1) = 7; d(n) = 3;
e(1) = 0; f(1) = 0; b(n) = 0.5*h^3;

