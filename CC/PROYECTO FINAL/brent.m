function root = brent(func,a,b,tol)
% Finds a root of f(x) = 0 by combining quadratic
% interpolation with bisection (Brent's method).
% USAGE: root = brent(func,a,b,tol)
% INPUT:
% func = handle of function that returns f(x).
% a,b  = limits of the interval containing the root.
% tol  = error tolerance (default is 1.0e6*eps).
% OUTPUT:
% root = zero of f(x) (root = NaN if failed to converge).

if nargin < 4; tol = 1.0e6*eps; end
% First step is bisection
x1 = a; f1 = polyval(func,x1);
if f1 == 0; root = x1; return; end
x2 = b; f2 = polyval(func,x2);
if f2 == 0; root = x2; return; end
if f1*f2 > 0.0
    error('Root is not bracketed in (a,b)')
end
x3 = 0.5*(a + b);
% Beginning of iterative loop.
for i = 1:30
    f3 = polyval(func,x3);
    if abs(f3) < tol
        root = x3; return
    end
    % Tighten brackets (a,b) on the root.
    if f1*f3 < 0.0; b = x3;
    else; a = x3;
    end
    if (b - a) < tol*max(abs(b),1.0)
        root = 0.5*(a + b); return
    end    
    % Try quadratic interpolation.
    denom = (f2 - f1)*(f3 - f1)*(f2 - f3);
    numer = x3*(f1 - f2)*(f2 - f3 + f1)...
        + f2*x1*(f2 - f3) + f1*x2*(f3 - f1);
    % If division by zero, push x out of bracket
    % to force bisection.
    if denom == 0; dx = b - a;
    else; dx = f3*numer/denom;
    end
    x = x3 + dx;
    % If interpolation goes out of bracket, use bisection.
    if (b - x)*(x - a) < 0.0
        dx = 0.5*(b - a); x = a + dx;
    end
    % Let x3 <-- x & choose new x1, x2 so that x1 < x3 < x2.
    if x < x3
        x2 = x3; f2 = f3;
    else
        x1 = x3; f1 = f3;
    end
    x3 = x;
end
root = NaN;

    

        
    
   
