function fDiff7
% Finite difference method for the second-order,
% nonlinear boundary value problem in Example 8.7.

global N H X                 % Make these params. global.
xStart = 0; xStop = 2;       % Range of integration.
N = 11;                      % Number of mesh points.
freq = 1;                    % Printout frequency.
X = linspace(xStart,xStop,N)';
y = 0.5*X;                   % Starting values of y.

H = (xStop - xStart)/(N-1);
y = newtonRaphson2(@residual,y,1.0e-5);
printSol(X,y,freq)

function r = residual(y);
% Residuals of finite difference equations (left-hand
% sides of Eqs (8.11).
global N H X
r = zeros(N,1);
r(1) = y(1); r(N) = y(N) - 1;
for i = 2:N-1
    r(i) = y(i-1) - 2*y(i) + y(i+1)...
         - H*H*y2Prime(X(i),y(i),(y(i+1) - y(i-1))/(2*H));
end

function F = y2Prime(x,y,yPrime)
% Second-order differential equation F = y".
F = -3*y*yPrime;
