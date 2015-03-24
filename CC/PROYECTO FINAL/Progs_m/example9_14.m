% Example 9.14 (Eigenvalue problem)
global C D
m = 3;
A = [11  2  3  1  4;
      2  9  3  5  2;
      3  3 15  4  3;
      1  5  4 12  4;
      4  2  3  4 17];
eVecMat = zeros(size(A,1),m);       % Init. eigenvector matrix.
A = householder(A);                 % Tridiagonalize A.
D = diag(A); C = diag(A,1);         % Extract diagonals of A.
P = householderP(A);                % Compute tranf. matrix P.
eVals = eigenvals3(C,D,m);          % Find lowest m eigenvals.
for i = 1:m                         % Compute corresponding
    s = eVals(i)*1.0000001;         %    eigenvectors by inverse
    [eVal,eVec] = invPower3(C,D,s); %    power method with
    eVecMat(:,i) = eVec;            %    eigenvalue shifting.
end
eVecMat = P*eVecMat;                % Eigenvecs. of orig. A.
eigenvalues = eVals'
eigenvectors = eVecMat



