function root = newtonRaphson(func,dfunc,a,b,tol)
% Newton-Raphson method combined with bisection for
% finding a root of f(x) = 0.
% USAGE: root = newtonRaphson(func,dfunc,a,b,tol)
% INPUT:
% func  = handle of function that returns f(x).
% dfunc = handle of function that returns f'(x).
% a,b   = brackets (limits) of the root.
% tol   = error tolerance (default is 1.0e6*eps).
% OUTPUT:
% root = zero of f(x) (root = NaN if no convergence).

if nargin < 5; tol = 1.0e6*eps; end
fa = polyval(func,a); fb = polyval(func,b);
if fa == 0; root = a; return; end
if fb == 0; root = b; return; end
if fa*fb > 0.0
    error('Root is not bracketed in (a,b)')
end
x = (a + b)/2.0;
for i = 1:30
    fx = polyval(func,x);
    if abs(fx) < tol; root = x; return; end
    % Tighten brackets on the root
    if fa*fx < 0.0; b = x;
    else; a = x;
    end
    % Try Newton-Raphson step
    dfx = polyval(dfunc,x);
    if abs(dfx) == 0; dx = b - a;
    else; dx = -fx/dfx;
    end
    x = x + dx;
    % If x not in bracket, use bisection
    if (b - x)*(x - a) < 0.0
        dx = (b - a)/2.0;
        x = a + dx;
    end
    % Check for convergence
    if abs(dx) < tol*max(b,1.0)
        root = x; return
    end
end
root = NaN
