% Example 10.1 (golden section minimization)
x = 1.0; h = 0.1;
[a,b] = goldBracket(@fex10_1,x,h);
[xMin,fMin] = goldSearch(@fex10_1,a,b)