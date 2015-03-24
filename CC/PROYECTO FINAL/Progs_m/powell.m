function [xMin,fMin,nCyc] = powell(h,tol)
% Powell's method for minimizing f(x1,x2,...,xn).
% USAGE: [xMin,fMin,nCyc] = powell(h,tol)
% INPUT:
% h   = initial search increment (default = 0.1).
% tol = error tolerance (default = 1.0e-6).
% GLOBALS (must be declared GLOBAL in calling program):
% X = starting point
% FUNC = handle of function that returns f.
% OUTPUT:
% xMin = minimum point
% fMin = miminum value of f
% nCyc = number of cycles to convergence

global X FUNC V
if nargin < 2; tol = 1.0e-6; end
if nargin < 1; h = 0.1; end
if size(X,2) > 1; X = X'; end  % X must be column vector
n = length(X);    % Number of design variables             
df = zeros(n,1);  % Decreases of f stored here
u = eye(n);       % Columns of u store search directions V
for j = 1:30      % Allow up to 30 cycles
    xOld = X;
    fOld = feval(FUNC,xOld);
    % First n line searches record the decrease of f
    for i = 1:n
        V = u(1:n,i);
        [a,b] = goldBracket(@fLine,0.0,h);
        [s,fMin] = goldSearch(@fLine,a,b);
        df(i) = fOld - fMin;
        fOld = fMin;
        X = X + s*V;
    end
    % Last line search in the cycle
    V = X - xOld;
    [a,b] = goldBracket(@fLine,0.0,h);
    [s,fMin] = goldSearch(@fLine,a,b);
    X = X + s*V;
    % Check for convergence
    if sqrt(dot(X-xOld,X-xOld)/n) < tol
        xMin = X; nCyc = j; return
    end
    % Identify biggest decrease of f & update search
    % directions
    iMax = 1; dfMax = df(1);
    for i = 2:n
        if df(i) > dfMax
            iMax = i; dfMax = df(i);
        end
    end
    for i = iMax:n-1
        u(1:n,i) = u(1:n,i+1);
    end
    u(1:n,n) = V;
end
error('Powell method did not converge')

function z = fLine(s) % F in the search direction V
global X FUNC V
z = feval(FUNC,X+s*V);