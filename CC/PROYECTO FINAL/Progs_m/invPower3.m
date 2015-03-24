function [eVal,eVec] = invPower3(c,d,s,maxIter,tol)
% Computes the eigenvalue of A =[c\d\c] closest to s and 
% the associated eigenvector by the inverse power method.
% USAGE: [eVal,eVec] = invPower3(c,d,s,maxIter,tol).
% maxIter = limit on number of iterations (default is 50).
% tol = error tolerance (default is 1.0e-6).

if nargin < 5; tol = 1.0e-6; end
if nargin < 4; maxIter = 50; end
n = length(d);
e = c; d = d - s;         % Apply shift to diag. terms of A
[c,d,e] = LUdec3(c,d,e);  % Decompose A* = A - sI
x = rand(n,1);            % Seed x with random numbers
xMag = sqrt(dot(x,x)); x = x/xMag; % Normalize x
for i = 1:maxIter
    xOld = x;                      % Save current x
    x = LUsol3(c,d,e,x);           % Solve A*x = xOld
    xMag = sqrt(dot(x,x)); x = x/xMag;  % Normalize x
    xSign = sign(dot(xOld,x));     % Detect sign change of x
    x = x*xSign;
    % Check for convergence
    if sqrt(dot(xOld - x,xOld - x)) < tol
        eVal = s + xSign/xMag; eVec = x;       
        return
    end
end
error('Too many iterations')