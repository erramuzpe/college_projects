function [a,b] = goldBracket(func,x1,h)
% Brackets the minimum point of f(x).
% USAGE: [a,b] = goldBracket(func,xStart,h)
% INPUT:
% func   = handle of function that returns f(x).
% x1     = starting value of x.
% h      = initial step size used in search.
% OUTPUT:
% a, b = limits on x at the minimum point.

c = 1.618033989;
f1 = feval(func,x1);
x2 = x1 + h; f2 = feval(func,x2);
% Determine downhill direction & change sign of h if needed.
if f2 > f1
    h = -h;
    x2 = x1 + h; f2 = feval(func,x2);
    % Check if minimum is between x1 - h and x1 + h
    if f2 > f1 
        a = x2; b = x1 - h; return
    end
end
% Search loop
for i = 1:100
    h = c*h;
    x3 = x2 + h; f3 = feval(func,x3);
    if f3 > f2
        a = x1; b = x3; return
    end
    x1 = x2; f1 = f2; x2 = x3; f2 = f3;
end
error('goldbracket did not find minimum')