function shoot3
% Shooting method for 3rd-order boundary value
% problem in Example 8.3.

global XSTART XSTOP H    % Make these params. global.
XSTART = 5; XSTOP = 0;   % Range of integration.
H = -0.1;                % Step size.
freq = 2;                % Frequency of printout.
u1 = 1; u2 = 2;          % Trial values of unknown
                         % initial condition u.
x = XSTART;
u = linInterp(@residual,u1,u2);
[xSol,ySol] = runKut5(@dEqs,x,inCond(u),XSTOP,H);
printSol(xSol,ySol,freq)

function F = dEqs(x,y)   % 1st-order differential eqs.
F = [y(2), y(3), 2*y(3) + 6*x*y(1)];

function y = inCond(u)   % Initial conditions.
y = [0 0 u];

function r = residual(u) % Boundary residual.
global XSTART XSTOP H    
x = XSTART;
[xSol,ySol] = runKut5(@dEqs,x,inCond(u),XSTOP,H);
r = ySol(size(ySol,1),1) - 2;