function shoot4
% Shooting method for 4th-order boundary value
% problem in Example 8.4.

global XSTART XSTOP H     % Make these params. global.
XSTART = 0; XSTOP = 1;    % Range of integration.
H = 0.5;                  % Step size.
freq = 1;                 % Frequency of printout.
u = [0 1];                % Trial values of u(1) 
                          % and u(2).
x = XSTART;
u = newtonRaphson2(@residual,u);
[xSol,ySol] = bulStoer(@dEqs,x,inCond(u),XSTOP,H);
printSol(xSol,ySol,freq)

function F = dEqs(x,y)    % Differential equations
F = [y(2) y(3) y(4) x;];

function y = inCond(u)    % Initial conditions; u(1)
y = [0 u(1) 0 u(2)];      % and u(2) are unknowns.

function r = residual(u)  % Boundary residuals.
global XSTART XSTOP H
r = zeros(length(u),1);
x = XSTART;
[xSol,ySol] = bulStoer(@dEqs,x,inCond(u),XSTOP,H);
lastRow = size(ySol,1);
r(1 )= ySol(lastRow,1);
r(2) = ySol(lastRow,3);