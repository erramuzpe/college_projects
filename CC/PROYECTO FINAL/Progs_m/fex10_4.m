function y = fex10_4(X)
% Function used in Example 10.4
lam = 1.0;                    % Penalty multiplier
c = X(1)*X(2) - 5.0;          % Constraint equation
distSq = (X(1) - 5.0)^2 + (X(2) - 8.0)^2;
y = distSq + lam*c^2;