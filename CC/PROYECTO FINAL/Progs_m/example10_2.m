% Example 10.2 (root finding with golden section)
yStart = 60.0; h = 1.0;
[a,b] = goldBracket(@fex10_2,yStart,h);
[yopt,Sopt] = goldSearch(@fex10_2,a,b);
fprintf('optimal y = %7.4f\n',yopt)
fprintf('optimal S = %7.2f',-Sopt)