% Example 9.3 (Jacobi method)
n = 10;                        % Number of interior nodes
A = zeros(n); B = zeros(n);    % Start constructing A and B
for i = 1:n
    A(i,i) = 6; B(i,i) = 2;
end
A(1,1) = 5; A(n,n) = 7;
for i = 1:n-1
    A(i,i+1) = -4; A(i+1,i) = -4;
    B(i,i+1) = -1; B(i+1,i) = -1;
end
for i = 1:n-2
    A(i,i+2) = 1; A(i+2,i) = 1;
end
[H,T] = stdForm(A,B);          % Convert to std. form
[eVals,Z] = jacobi(H);         % Solve by Jacobi method
X = T*Z;                       % Eigenvectors of orig. prob.
for i = 1:n                    % Normalize eigenvectors
    xMag = sqrt(dot(X(:,i),X(:,i)));
    X(:,i) = X(:,i)/xMag;
end
[eVals,X] = sortEigen(eVals,X); % Sort in ascending order
eigenvalues = eVals(1:3)'       % Extract 3 smallest  
eigenvectors = X(:,1:3)         % eigenvalues & vectors

    