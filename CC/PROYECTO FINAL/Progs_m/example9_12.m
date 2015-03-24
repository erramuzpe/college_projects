% Example 9.12 (Eigenvals. of tridiagonal matrix)
format short e
global C D
m =3; n = 100;
D = ones(n,1)*2;
C = -ones(n-1,1);
eigenvalues = eigenvals3(C,D,m)'
