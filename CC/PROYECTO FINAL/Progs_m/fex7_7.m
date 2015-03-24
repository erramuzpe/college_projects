function F = fex7_7(x,y)
% Diff. eqs. used in Example 7.7
F = zeros(1,2);
F(1) = y(2);
F(2) = -4.75*y(1) - 10*y(2);
