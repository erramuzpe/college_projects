function I = gaussQuad(func,a,b,n)
% Gauss-Legendre quadrature.
% USAGE: I = gaussQuad(func,a,b,n)
% INPUT:
% func = handle of function to be integrated.
% a,b  = integration limits.
% n    = order of integration.
% OUTPUT:
% I = integral

c1 = (b + a)/2; c2 = (b - a)/2;   % Mapping constants
[x,A] = gaussNodes(n);            % Nodal abcsissas & weights
sum = 0;
for i = 1:length(x)
    y = feval(func,c1 + c2*x(i)); % Function at node i
    sum = sum + A(i)*y;
end
I = c2*sum;