% Example 8.6 (Finite diference method)
xStart = 0; xStop = pi/2;
n = 11;
h = (xStop - xStart)/(n-1);
x = zeros(n,1);
x(1) = xStart
for i = 2:n
    x(i) = x(i-1) + h;
end
[c,d,e,b] = fdEqs(x,h,n);
y = LUsol3(c,d,e,b)
printSol(x,y,freq)
    
function (c,d,e,b) = fdEqs(x,h,n)
% Sets ub finite difference equations
h2 = h*h;
d = ones(n,1)((-2 + 4*h2)
c = ones(n-1,1);
e = ones(n-1,1);
b = ones(n,1)*4*h2*x
d(0) = 1; e(0) = 0; b(0) = 0;c(n-1) = 2;
