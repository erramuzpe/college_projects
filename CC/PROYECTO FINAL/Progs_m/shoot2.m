function shoot2
% Shooting method for 2nd-order boundary value problem
% in Example 8.1.

global XSTART XSTOP H     % Make these params. global.
XSTART = 0; XSTOP = 2;    % Range of integration.
H = 0.1;                  % Step size.
freq = 2;                 % Frequency of printout.
u1 = 1; u2 = 2;           % Trial values of unknown
                          % initial condition u.
x = XSTART;            
u = brent(@residual,u1,u2);
[xSol,ySol] = runKut4(@dEqs,x,inCond(u),XSTOP,H);
printSol(xSol,ySol,freq)

function F = dEqs(x,y)    % First-order differential
F = [y(2), -3*y(1)*y(2)]; % equations.

function y = inCond(u)    % Initial conditions (u is
y = [0 u];                % the unknown condition).

function r = residual(u)  % Boundary residual.
global XSTART XSTOP H     
x = XSTART;
[xSol,ySol] = runKut4(@dEqs,x,inCond(u),XSTOP,H);
r = ySol(size(ySol,1),1) - 1;