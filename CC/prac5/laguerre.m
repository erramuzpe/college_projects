function [neg pos]=laguerre(p,maxIter)

% Calcula, mediante el método de Laguerre-Thibault, una cota m y otra M para las que
% se cumple que todas las raíces del polinomio están en el intervalo (m,M)
% Entrada: coeficientes del polinomio
%          (ejemplo: para 2*x^3 -x +2 sería [2 0 -1 2]).
%          nº máximo de iteraciones.
% Salida: cotas inferior y superior de las raíces del polinomio, si una no
% la encuentra  de vuelve cero.

    % cota positiva:
    esCota=false;
    iterActual=0;    
    L=1;
    % si el primer coeficiente es negativo hay que evaluar -p(x)
    if p(1)<0
        p1=-p;
    else
        p1=p;
    end
    while (~esCota && iterActual<maxIter)


  	% deconv nos da cociente y resto de dos polinomios
        [q r]=deconv(p1,[1 -L]);

        q=[0 q];

        % comprueba si todos los coeficientes son positivos o nulos
        i=1;
        while (i<length(q)) && (q(i)>=0 && r(i)>=0)
            i=i+1;
        end

        esCota=(q(i)>=0 && r(i)>=0);
        iterActual=iterActual+1;
        L=L+1;
    end
    
    if (esCota)
        pos=L;
    else
        pos=0;
    end
    
    % cota negativa:
    esCota=false;
    iterActual=0;    
    L=1;
    % hay que evaluar p(-x)
    for i=1:length(p)
        if mod(i,2)~=0
            p2(i)=-p(i);
        else
            p2(i)=p(i);
        end
    end
    
    % si el primer coeficiente es negativo hay que evaluar -p2(x)
    if p2(1)<0
        p2=-p2;
    end
    
    while (~esCota && iterActual<maxIter)


  	% deconv nos da cociente y resto de dos polinomios
        [q r]=deconv(p2,[1 -L]);

        q=[0 q];

        % comprueba si todos los coeficientes son positivos o nulos
        i=1;
        while (i<length(q)) && (q(i)>=0 && r(i)>=0)
            i=i+1;
        end

        esCota=(q(i)>=0 && r(i)>=0);
        iterActual=iterActual+1;
        L=L+1;
    end
    
    if (esCota)
        neg=-L;
    else
        neg=0;
    end
    
end 
