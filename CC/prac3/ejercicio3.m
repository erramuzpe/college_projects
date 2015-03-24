%Asier Erramuzpe Prac3
%Grupo A:Ejercicio 3
%El ultimo numero es el indice del minimo!
%Funcion que encuentra los minimos locales de una funcin discreta. Como entrada
%recibe un vector que representa el valor de la funcin en las posiciones x=1, x=2,  Como salida
%devuelve un vector con las posiciones donde se encuentran los mnimos locales de la funcion, as
%como un nmero indicando la posicin del mnimo global.

function [m] = ejercicio3(v)
    z = length(v);
    m = [];
    minimo= v(1);
    posicion= 1;
    
    for i=1
        if v(i)<v(i+1) 
            m=[m i];
        end
     end   
    
    for i=2:z-1
        if v(i)<v(i+1) && v(i)<v(i-1)
            m=[m i];
        end
        if v(i) < minimo
            minimo = v(i); 
            posicion = i;
       end
    end
    
    for i=z
        if v(z)<v(z-1)
            m=[m i];
        end
        if v(z) < minimo
            minimo = v(z); 
            posicion = i;
       end
    end
    posicion
end