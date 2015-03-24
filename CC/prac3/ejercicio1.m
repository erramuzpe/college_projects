%Asier Erramuzpe Prac3
%Grupo A:Ejercicio 1
%Función a la que le entre un vector y devuelva en una matriz la distancia entre cada
%par de elementos del vector. La distancia será calculada como la diferencia entre cada dos
%elementos, siendo siempre mayor o igual que cero.


function [m] = ejercicio1(v)
    tic;
    z = length(v);
    m = zeros(z,z);
    for i=1:z
        for j=1:z
            m(i,j) = max(v(i),v(j))-min(v(i),v(j));
        end
    end
    %tiempo
    toc;
end

