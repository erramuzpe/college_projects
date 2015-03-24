function [xMin,fMin,nCyc] = fletcherReeves(h,tol)
% Fletcher-Reeves method for minimizing f(x1,x2,...,xn).
% USAGE: [xMin,fMin,nCyc] = fletcherReeves(h,tol)
% INPUT:
% h   = initial search increment (default = 0.1).
% tol = error tolerance (default = 1.0e-6).
% GLOBALS (must be declared GLOBAL in calling program):
% X     = starting point.
% FUNC  = handle of function that returns f.
% DFUNC = handle of function that returns grad(f),
% OUTPUT:
% xMin = minimum point.
% fMin = miminum value of f.
% nCyc = number of cycles to convergence.

global X FUNC DFUNC V
if nargin < 2; tol = 1.0e-6; end
if nargin < 1; h = 0.1; end
if size(X,2) > 1; X = X'; end  % X must be column vector
n = length(X);                 % Number of design variables  
g0 = -feval(DFUNC,X);
V = g0;
for i = 1:50
    [a,b] = goldBracket(@fLine,0.0,h);
    [s,fMin] = goldSearch(@fLine,a,b);
    X = X + s*V;
    g1 = -feval(DFUNC,X);
    if sqrt(dot(g1,g1)) <= tol
        xMin = X; nCyc = i; return
    end
    gamma = dot((g1 - g0),g1)/dot(g0,g0);
    V = g1 + gamma*V;
    g0 = g1;
end
error('Fletcer-Reeves method did not converge')

function z = fLine(s) % F in the search direction V
global X FUNC V
z = feval(FUNC,X+s*V);