function [L, U] = crout ()
    n = input('Introduce el numero de ecuaciones que forman el sistema: ');
    ecuaciones = zeros(n,n);
    indep=zeros(n, 1);
    for x=1:n
        fprintf('Introduce los coeficientes de la ecuación %d\n', x);
        for i=1:n
            fprintf('Ecuación %d, coeficiente %d: ', x, i);
            ecuaciones(x, i) = input('');
        end
        fprintf('Ecuación %d, parte independiente: ', x);
        indep(x) = input('');
    end
    
    L = zeros(n);
    U = zeros(n);
    L(1, 1) = 1;
    U(1, 1) = ecuaciones(1,1);
    for j=2:n
        L(j, j) = 1;
        L(j, j-1) = ecuaciones(j, j-1) / U(j-1, j-1);
        U(j-1, j) = ecuaciones(j-1, j);
        U(j, j) = ecuaciones(j, j) - L(j, j-1)*U(j-1, j);
    end
    
    ecuaciones
    L
    U
end
