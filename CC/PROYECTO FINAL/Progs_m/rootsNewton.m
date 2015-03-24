function rootsNewton(func,dfunc,a,b,dx,tol)
% Computes all the roots of f(x) in the interval (a,b)
% with the Newton-Raphson method.
% USAGE: rootsNewton(func,a,b,dx,tol)
% func  = handle of function that returns f(x)
% dfunc = handle of function that returns f'(x)
% dx    = increment of x used in root search
% tol   = error tolerance (default is 10.e-6)

if nargin < 6; tol = 1.0e-6; end
fprintf('Roots:\n')
while 1
    [x1,x2] = rootsearch(func,a,b,dx);
    if isnan(x1)
        fprintf('Done'); break
    else
        a = x2;
        x = newtonRaphson(func,dfunc,x1,x2,tol);
        if isnan(x); continue
        else fprintf('%16.6e\n', x); end
    end
end    
    

