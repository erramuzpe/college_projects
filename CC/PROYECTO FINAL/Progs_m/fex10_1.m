function y = fex10_1(x)
% Function used in Example 10.1.
lam = 1.0;      % Penalty function multiplier
c = min(0.0,x);  % Constraint penalty equation
y = 1.6*x^3 + 3.0*x^2 - 2.0*x + lam*c^2;