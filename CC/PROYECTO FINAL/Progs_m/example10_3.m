% Example 10.3 (Powell's method of minimization)
global X FUNC
FUNC = @fex10_3;
X = [-1.0; 1.0];
[xMin,fMin,numCycles] = powell