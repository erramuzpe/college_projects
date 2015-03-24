%Asier Erramuzpe Prac3
%Grupo A:Ejercicio 5 forma 2
%Introducimos 2 numeros y nos devuelve su MCD

function  mcd =ejercicio5f2(x,y)
    tic;
    mcd=min(x,y);
    while (mod(x,mcd)~=0 || mod(y,mcd)~=0) && mcd>1   % empezamos el bucle por arriba, de esta forma el mcd es el primero que se encuentra
        mcd=mcd-1;
    end  
    toc;
end
