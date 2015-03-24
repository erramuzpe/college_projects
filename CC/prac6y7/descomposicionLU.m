function [L, U] = descomposicionLU()
    n = input('Introduce el numero de ecuaciones que forman el sistema: ');
    ecuaciones = zeros(n,n,n);
    indep=zeros(n, 1);
    for x=1:n
        fprintf('Introduce los coeficientes de la ecuación %d\n', x);
        for i=1:n
            fprintf('Ecuación %d, coeficiente %d: ', x, i);
            ecuaciones(x, i, 1) = input('');
        end
        fprintf('Ecuación %d, parte independiente: ', x);
        indep(x) = input('');
    end
    
    
    for i=1:n
        ecuaciones(:,:,i)
        if i==n  
            U = ecuaciones(:,:,n);
            U
        else
            if ecuaciones(i, i, i) == 0
                disp('No se puede realizar el método de descomposición LU');
                disp('Se ha encontrado un pivote = 0 en la diagonal');
                return;     
            else
                ecuaciones(:,:,i+1) = ecuaciones(:,:,i);
                for j=i+1:n
                    num = ecuaciones(j, i, i+1)/ecuaciones(i, i, i+1);
                    ecuaciones(j,:,i+1) = ecuaciones(j,:,i+1) - num*ecuaciones(i,:,i+1);
                    indep(j) = indep(j) - num*indep(i);                
                end
            end
        end
    end
    
    L = zeros(n,n);
    for i=1:n
        L(i,i) = 1;
        for j=i+1:n
            L(j,i) = ecuaciones(j,i,i) / ecuaciones(i,i,i);
        end
    end
    L
end