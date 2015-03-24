function [x,numIter] = solve(func,x,epsilon)
class(func)
if nargin == 2; epsilon = 1.0e-6; end
for numIter = 1:100
    dx = feval(func,x);
    x = x + dx;
    if abs(dx) < epsilon; return; end
end
error('Too many iterations')
