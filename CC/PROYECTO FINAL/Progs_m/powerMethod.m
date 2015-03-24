function [eVal,eVec] = powerMethod(A,maxIter,tol)
% Power method for finding the largest eigenvalue of A and
% the correstponding eigenvector.
% USAGE: [eVal,eVec] = invPower(A,maxIter,tol)
% maxIter = limit on number of iterations (default is 50).
% tol = error tolerance (default is 1.0e-6).

if nargin < 3; tol = 1.0e-6; end
if nargin < 2; maxIter = 50; end
n = size(A,1);
v = rand(n,1);
vMag = v/sqrt(dot(v,v));
for i = 1:maxIter
    z = A*v;
    zMag = sqrt(dot(z,z)); z = z/zMag;
    if sqrt(dot(v - z,v - z)) < tol
        if dot(v,z) > 0; eVal = zMag;
        else; eVal = -zMag; end
        eVec = z; return
    end    
    v = z;
end
error('Too many iterations')
