function L = choleski(A)
% Computes L in Choleski's decomposition A = LL'.
% USAGE: L = choleski(A)

n = size(A,1);
for j = 1:n
    temp = A(j,j) - dot(A(j,1:j-1),A(j,1:j-1));
    if temp < 0.0
        error('Matrix is not positive definite')
    end
    A(j,j) = sqrt(temp);
    for i = j+1:n
        A(i,j)=(A(i,j) - dot(A(i,1:j-1),A(j,1:j-1)))/A(j,j);
    end
end
L = tril(A); 