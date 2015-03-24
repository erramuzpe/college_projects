function shoot2_matlab
% Solution of Example 8.1 with MATLAB's function bvp4c,

xinit = linspace(0,2,11)';  
solinit = bvpinit(xinit,@yguess);
sol = bvp4c(@dEqs,@residual,solinit);
y = deval(sol,xinit)';
printSol(xinit,y,1)

function F = dEqs(x,y)    % Differential equations.
F = [y(2); -3*y(1)*y(2)];

function r = residual(ya,yb) % Boundary residuals.
r = [ya(1); yb(1) - 1];    

function yinit = yguess(x)   % Initial guessses for
yinit = [0.5*x; 0.5];        % y1 and y2.



