% Example 9.6 (Inverse power method for pentadiagonal A)
n = 100;
d = ones(n,1)*6;
d(1) = 5; d(n) = 7;
e = ones(n-1,1)*(-4);
f = ones(n-2,1);
[eVal,eVec] = invPower5(@fex9_6,d,e,f);
fprintf('PL^2/EI =')
fprintf('%9.4f',eVal*(n+1)^2)