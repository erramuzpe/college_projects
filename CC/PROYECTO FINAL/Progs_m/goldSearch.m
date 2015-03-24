function [xMin,fMin] = goldSearch(func,a,b,tol)
% Golden section search for the minimum of f(x).
% The minimum point must be bracketed in a <= x <= b.
% USAGE: [fMin,xMin] = goldSearch(func,xStart,h)
% INPUT:
% func   = handle of function that returns f(x).
% a, b   = limits of the interval containing the minimum.
% tol    = error tolerance (default is 1.0e-6).
% OUTPUT:
% fMin = minimum value of f(x).
% xMin = value of x at the minimum point.

if nargin < 4; tol = 1.0e-6; end
nIter = ceil(-2.078087*log(tol/abs(b-a)));
R = 0.618033989;
C = 1.0 - R;
% First telescoping
x1 = R*a + C*b;
x2 = C*a + R*b;
f1 = feval(func,x1);
f2 = feval(func,x2);
% Main loop
for i =1:nIter
    if f1 > f2
        a = x1; x1 = x2; f1 = f2;
        x2 = C*a + R*b;
        f2 = feval(func,x2);
    else
        b = x2; x2 = x1; f2 = f1;
        x1 = R*a + C*b;
        f1 = feval(func,x1);
    end
end    
if f1 < f2; fMin = f1; xMin = x1;
else; fMin = f2; xMin = x2;  
end