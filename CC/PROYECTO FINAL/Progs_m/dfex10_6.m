function g = dfex10_6(X)
% Function defining del(F) in Example 10.6
g = zeros(2,1);
g(1) = -8.0/(X(1)^2) - tan(X(2)) + 2.0/cos(X(2));
g(2) = X(1)*(-1.0/cos(X(2)) + 2.0*tan(X(2)))/cos(X(2));
