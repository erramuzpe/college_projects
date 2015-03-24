function Bv = prod_Bv(v)
% Computes the product B*v in Example 9.6

n = length(v);
Bv = zeros(n,1);
for i = 2:n-1
    Bv(i) = -v(i-1) + 2*v(i) - v(i+1);
end
Bv(1) = 2*v(1) - v(2);
Bv(n) = -v(n-1) + 2*v(n);