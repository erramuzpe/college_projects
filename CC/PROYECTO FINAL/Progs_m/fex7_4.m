function F = fex7_4(x,y)
% Differential. eqs. used in Example 7.4

F = zeros(1,2);
F(1) = y(2); F(2) = -0.1*y(2) - x;
