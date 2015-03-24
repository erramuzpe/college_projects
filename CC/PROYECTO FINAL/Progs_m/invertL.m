function Linv = invertL(L)
% Inverts a lower triangualr matrix [L].
% USAGE: Linv = invertL(L)
n = size(L,1);
Linv = eye(n);
for i =1:n
    Linv(:,i) = solve(L,Linv(:,i));
end

function b = solve(L,b)
% Solves [L]{x} = {b} where [L] is lower triangular
n = size(L,1);
b(1)=b(1)/L(1,1);
for i = 2:n
    b(i) = (b(i) - dot(L(i,1:i-1),b(1:i-1)))/L(i,i);
end