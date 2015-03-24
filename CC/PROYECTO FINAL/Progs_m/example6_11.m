% Example 6.11 (Gauss-Legendre quadrature)
a = 0; b = pi; Iexact = 1.41815;
for n = 2:12
    I = gaussQuad(@fex6_11,a,b,n);
    if abs(I - Iexact) < 0.00001
        I
        n
        break
    end
end    
    
    
        
        
      
