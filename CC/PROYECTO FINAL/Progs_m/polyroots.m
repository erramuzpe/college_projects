function root = polyroots(a,tol)
% Returns all the roots of the polynomial 
% a(1)*x^n + a(2)*x^(n-1) + ... + a(n+1).
% USAGE: root = polyroots(a,tol).
% tol = error tolerance (default is 1.0e4*eps).

if nargin == 1; tol = 1.0e-6; end
n = length(a) - 1;
root = zeros(n,1);
for i = 1:n
    x = laguerre(a,tol);
    if abs(imag(x)) < tol; x = real(x); end
    root(i) = x;
    a = deflpoly(a,x);
end
    
function x = laguerre(a,tol)
% Returns a root of the polynomial 
% a(1)*x^n + a(2)*x^(n-1) + ... + a(n+1).
x = randn;            % Start with random number
n = length(a) - 1;
for i = 1:30
    [p,dp,ddp] = evalpoly(a,x);
    if abs(p) < tol; return; end
    g = dp/p; h = g*g - ddp/p;
    f = sqrt((n - 1)*(n*h - g*g));
    if abs(g + f) > abs(g - f); dx = n/(g + f);
    else; dx = n/(g - f); end
    x = x - dx;
    if abs(dx) < tol*max(abs(x),1.0); return; end
end
error('Too many iterations in laguerre')

function b = deflpoly(a,r)
% Horner's deflation: 
% a(1)*x^n + a(2)*x^(n-1) + ... + a(n+1)
% = (x - r)[b(1)*x^(n-1) + b(2)*x^(n-2) + ...+ b(n)].
n = length(a) - 1;
b = zeros(n,1);
b(1) = a(1);
for i = 2:n; b(i) = a(i) + r*b(i-1); end
    

