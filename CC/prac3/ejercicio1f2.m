%Asier Erramuzpe Prac3
%Grupo A:Ejercicio 1 forma 2
%Esta funcion recibe un vector y lo convierte en la matriz deseada.
%devuelva en una matriz la distancia entre cada par de elementos del vector. La distancia será calculada como la diferencia entre cada dos elementos, siendo siempre mayor o igual que cero.



function [m] = ejercicio1f2(v)
    tic;
    z = length(v);
    m = zeros(z,z);
    for i=1:z 
            m(i,:) = max(v(i),v(:))-min(v(i),v(:));
    end
    toc;
end