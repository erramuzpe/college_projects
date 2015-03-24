% Example 10.4 (Powell's method of minimization)
global X FUNC
FUNC = @fex10_4;
X = [1.0; 5.0];
[xMin,fMin,nCyc] = powell;
fprintf('Intersection point = %8.5f %8.5f\n',X(1),X(2))
xy = X(1)*X(2);
fprintf('Constraint x*y = %8.5f\n',xy)
dist = sqrt((X(1) - 5.0)^2 + (X(2) - 8.0)^2);
fprintf('Distance = %8.5f\n',dist)
fprintf('Number of cycles = %2.0f',nCyc)
