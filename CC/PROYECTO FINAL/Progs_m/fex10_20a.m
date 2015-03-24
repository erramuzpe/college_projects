function y = fex10_20a(x)
% Function used is solving Prob. 20, Problem Set 10.1
% by Lagrangian multipliers.
s = sin(x); c = cos(x);
y = [-6.0*c(1) - 1.2*x(4)*s(1) + 1.2*x(5)*c(1)
     -4.5*c(2) - 1.5*x(4)*s(2) + 1.5*x(5)*c(2)
     -x(4)*s(3) + x(5)*c(3)
     1.2*c(1) + 1.5*c(2) + c(3) - 3.5
     1.2*s(1) + 1.5*s(2) + s(3)];
