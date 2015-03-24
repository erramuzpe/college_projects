function hilbert(n)
% Solves A*x = b by LU decomposition with pivoting, where
% [A] is an n x n Hilbert matrix and b(i) is the sum of
% the elemnts in the ith row of [A].
% USAGE: hibert(n)

A = zeros(n); b = zeros(n,1);
for i = 1:n
    for j = 1:n
        A(i,j)= 1/(i + j - 1);
        b(i) = b(i) + A(i,j);
    end
end
A = LUdec(A); x = LUsol(A,b)

