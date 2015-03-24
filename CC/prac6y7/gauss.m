function valores = gauss ()
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
    
    
    for i=1:n
        if ecuaciones(i, i) == 0
            [ecuaciones, indep] = cambiarfila(ecuaciones, indep, i, n);
        end
        if ecuaciones(i, i) == 0
            disp('No se puede realizar el método de gauss, no hay suficientes ecuaciones independientes.');
            break;       
        else
            for j=i+1:n
                num = ecuaciones(j, i)/ecuaciones(i, i);
                ecuaciones(j,:) = ecuaciones(j,:) - num*ecuaciones(i,:);
                indep(j) = indep(j) - num*indep(i);                
            end
        end
    end
    
    valores = zeros(n,1);
    for i=1:n
        if i == 1
            valores(n-i+1) = indep(n-i+1)/ecuaciones(n-i+1, n-i+1);
        else
            valores(n-i+1) = (indep(n-i+1) - ecuaciones(n-i+1, n-i+2:n)*valores(n-i+2:n))/ecuaciones(n-i+1, n-i+1);
        end
    end
    valores
end

    function [ecuaciones, indep] = cambiarfila(ecuaciones, indep, i, n)
        for j=i+1:n
            if not (ecuaciones(j, i) == 0)
                aux1 = ecuaciones(i, :);
                aux2 = indep(j);
                ecuaciones(i, :) = ecuaciones(j, :);
                indep(i) = indep(j);
                ecuaciones(j, :) = aux1;
                indep(j) = aux2;
                break
            end
        end
    end
