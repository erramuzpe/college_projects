% Example 6.4 (Recursive trapezoidal rule)
format long   % Display extra precision
I2h = 0;
for k = 1:20
    Ih = trapezoid(@fex6_4,0,pi,I2h,k);
    if (k > 1 & abs(Ih - I2h) < 1.0e-6)
        Integral = Ih
        No_of_func_evaluations = 2^(k-1) + 1
        return
    end
    I2h = Ih;
end 
error('Too many iterations')
