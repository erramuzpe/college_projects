% Example 10.6 (Minimization with Fletcher-Reeves)
global X FUNC DFUNC
FUNC = @fex10_6; DFUNC = @dfex10_6;
X = [2.0;0.0];
[xMin,fMin,nCyc] = fletcherReeves;
b = 8.0/X(1) - X(1)*tan(X(2));
theta = X(2)*180.0/pi;  % Convert into degrees
fprintf('b = %8.5f\n',b)
fprintf('h = %8.5f\n',X(1))
fprintf('theta = %8.5f\n',theta)
fprintf('perimeter = %8.5f\n',fMin)
fprintf('number of cycles = %2.0f',nCyc)
