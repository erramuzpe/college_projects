function [eVal,eVec] = invPower5(func,d,e,f)
% Finds smallest eigenvalue of A*x = lambda*B*x by
% the inverse power method. 
% USAGE: [eVal,eVec] = invPower5(func,d,e,f)
% Matrix A must be pentadiagonal and stored in form 
%    A = [f\e\d\e\f]. 
% func = handle of function that returns B*v.

n = length(d);
[d,e,f] = LUdec5(d,e,f);           % Decompose A
x = rand(n,1);                     % Seed x with random numbers
xMag = sqrt(dot(x,x)); x = x/xMag; % Normalize x
for i = 1:50
    xOld = x;                           % Save current x
    x = LUsol5(d,e,f,feval(func,x));    % Solve [A]{x} = [B]{xOld}
    xMag = sqrt(dot(x,x)); x = x/xMag;  % Normalize x
    xSign = sign(dot(xOld,x));          % Detect sign change of x
    x = x*xSign; 
    % Check for convergence
    if sqrt(dot(xOld - x,xOld - x)) < 1.0e-6
        eVal = xSign/xMag; eVec = x;
        return
    end
end
error('Too many iterations')
       
