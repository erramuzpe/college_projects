% Example 9.13 (Eigenvals. of tridiagonal matrix)
format short e
m = 10
n = 100;
d = ones(n,1)*2; c = -ones(n-1,1);
r = eValBrackets(c,d,m);
s =(r(m) + r(m+1))/2;
[eVal,eVec] = invPower3(c,d,s);
mth_eigenvalue = eVal
