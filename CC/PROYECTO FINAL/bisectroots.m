% Example 4.3 (root finding with bisection)
tic
a = -2; b = 0.0; dx = 0.01;
nroots = 0;
while 1 
    [x1,x2] = rootsearch([2 3 1],a,b,dx);
    if isnan(x1)
        break
    else    
        a = x2;
        x = bisect([2 3 1],x1,x2,1);
        if ~ isnan(x)
            nroots = nroots + 1;
            root(nroots) = x;
        end
    end
end
root
       toc 
