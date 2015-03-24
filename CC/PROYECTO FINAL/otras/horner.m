function [y,b]=horner(a,z)
% Las variables de entrada son:
% a: Polinomio [an,...,a1,a0]
% z: Punto donde evaluamos
% Las variables de salida son: 
% y : cociente [bn-1,...,b1,b0]
% b: resto

n=length(a)-1;
b= zeros(n+1,1);
b(1)=a(1);
for j=2:n+1
    b(j)=a(j)+z*b(j-1);
end

y=b(n+1);
b=b(1:end-1);
return


