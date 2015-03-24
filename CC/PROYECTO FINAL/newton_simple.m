function [root,numIter] = newton_simple(func,dfunc,x,tol)
% Simple version of Newton-Raphson method used in Example
% 4.7.

if nargin < 5; tol = 1.0e6*eps; end
for i = 1:30
    dx = -feval(func,x)/feval(dfunc,x);
    x = x + dx;
    if abs(dx) < tol
        root = x; numIter = i; return
    end
end
root = NaN
