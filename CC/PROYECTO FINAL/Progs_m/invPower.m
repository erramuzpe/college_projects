function [eVal,eVec] = invPower(A,s,maxIter,tol)
% Inverse power method for finding the eigenvalue of A 
% closest to s & the correstponding eigenvector.
% USAGE: [eVal,eVec] = invPower(A,s,maxIter,tol)
% maxIter = limit on number of iterations (default is 50).
% tol = error tolerance (default is 1.0e-6).

if nargin < 4; tol = 1.0e-6; end
if nargin < 3; maxIter = 50; end
n = size(A,1);
A = A - eye(n)*s;   % Form A* = A - sI 
A = LUdec(A);       % Decompose A* 
x = rand(n,1);      % Seed eigenvecs. with random numbers
xMag = sqrt(dot(x,x)); x = x/xMag;      % Normalize x
for i = 1:maxIter
    xOld = x;       % Save current eigenvecs.
    x = LUsol(A,x); % Solve A*x = xOld
    xMag = sqrt(dot(x,x)); x = x/xMag;  % Normalize x 
    xSign = sign(dot(xOld,x)); % Detect sign change of x
    x = x*xSign;
    % Check for convergence
    if sqrt(dot(xOld - x,xOld - x)) < tol
        eVal = s + xSign/xMag; eVec = x;   
        return
    end
end
error('Too many iterations')
