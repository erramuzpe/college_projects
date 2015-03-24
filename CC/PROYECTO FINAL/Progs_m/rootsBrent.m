function rootsBrent(func,a,b,dx,tol)
% Computes all the roots of func(x) in the interval (a,b)
% with Brent's method.
% USAGE: roots(func,a,b,dx,tol)
% func = handle of function that returns f(x)
% dx   = increment of x used in root search
% tol  = error tolerance (default is 10.e-6)

if nargin < 5; tol = 1.0e-6; end
fprintf('Roots:\n')
while 1
    [x1,x2] = rootsearch(func,a,b,dx);
    if isnan(x1)
        fprintf('Done'); break
    else
        a = x2;
        x = brent(func,x1,x2,tol);
        if isnan(x); continue
        else fprintf('%16.6e\n', x); end
    end
end    
    

