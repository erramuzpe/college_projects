function [I,numEval] = romberg(func,a,b,tol,kMax)
% Romberg integration.
% USAGE: [I,numEval] = romberg(func,a,b,tol,kMax)
% INPUT:
% func    = handle of function being integrated.
% a,b     = limits of integration.
% tol     = error tolerance (default is 1.0e-8).
% kMax    = limit on the number of panel doublings
%          (default is 20).
% OUTPUT:
% I       = value of the integral.
% numEval = number of function evaluations.

if nargin < 5; kMax = 20; end
if nargin < 4; tol = 1.0e-8; end
r = zeros(kMax);
r(1) = trapezoid(func,a,b,0,1);
rOld = r(1);
for k = 2:kMax
    r(k) = trapezoid(func,a,b,r(k-1),k);
    r = richardson(r,k);
    if abs(r(1) - rOld) < tol
        numEval = 2^(k-1) + 1; I = r(1);
        return
    end
    rOld = r(1);
end    
error('Romberg failed to converge')
    
function r = richardson(r,k)
% Richardson's extrapolation in Eq. (6.14).
for j = k-1:-1:1
    c = 4^(k-j); r(j) = (c*r(j+1) - r(j))/(c-1);
end
    