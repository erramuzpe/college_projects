function [eVals,eVecs] = jacobi(A,tol)
% Jacobi method for computing eigenvalues and
% eigenvectors of a symmetric matrix A.
% USAGE: [eVals,eVecs] = jacobi(A,tol)
% tol = error tolerance (default is 1.0e-9).

if nargin < 2; tol = 1.0e-9; end
n = size(A,1);
maxRot = 5*(n^2);       % Limit number of rotations
P = eye(n);             % Initialize rotation matrix
for i = 1:maxRot        % Begin Jacobi rotations
    [Amax,k,L] = maxElem(A);
    if Amax < tol;
        eVals = diag(A); eVecs = P;
        return
    end
    [A,P] = rotate(A,P,k,L);
end
error('Too many Jacobi rotations')

function [Amax,k,L] = maxElem(A)
% Finds Amax = A(k,L) (largest off-diag. elem. of A).
n = size(A,1);
Amax = 0;
for i = 1:n-1
    for j = i+1:n
        if abs(A(i,j)) >= Amax
            Amax = abs(A(i,j));
            k = i; L = j;
        end
    end
end

function [A,P] = rotate(A,P,k,L)
% Zeros A(k,L) by a Jacobi rotation and updates
% transformation matrix P.
n = size(A,1);
diff = A(L,L) - A(k,k);
if abs(A(k,L)) < abs(diff)*1.0e-36
    t = A(k,L);
else
    phi = diff/(2*A(k,L));
    t = 1/(abs(phi) + sqrt(phi^2 + 1));
    if phi < 0; t = -t; end;
end
c = 1/sqrt(t^2 + 1); s = t*c;
tau = s/(1 + c);
temp = A(k,L); A(k,L) = 0;
A(k,k) = A(k,k) - t*temp; 
A(L,L) = A(L,L) + t*temp;
for i = 1:k-1                   % For i < k
    temp = A(i,k);
    A(i,k) = temp -s*(A(i,L) + tau*temp);
    A(i,L) = A(i,L) + s*(temp - tau*A(i,L));
end
for i = k+1:L-1                 % For k < i < L                                            
    temp = A(k,i);
    A(k,i) = temp - s*(A(i,L) + tau*A(k,i));
    A(i,L) = A(i,L) + s*(temp - tau*A(i,L));
end
for i = L+1:n                   % For i > L                      
    temp = A(k,i);
    A(k,i) = temp - s*(A(L,i) + tau*temp);
    A(L,i) = A(L,i) + s*(temp - tau*A(L,i));
end
for i = 1:n      % Update tranformation matrix
    temp = P(i,k);
    P(i,k) = temp - s*(P(i,L) + tau*P(i,k));
    P(i,L) = P(i,L) + s*(temp - tau*P(i,L));
end    
    