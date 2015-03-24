% Example 7.7 (Runge-Kutta integration)
x = 0;
xStop = 10;
y = [-9 0];
h = 0.5;
freq = 0;
[xSol,ySol] = runKut4(@fex7_7,x,y,xStop,h);
printSol(xSol,ySol,freq)