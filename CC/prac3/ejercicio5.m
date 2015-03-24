%Asier Erramuzpe Prac3
%Grupo A:Ejercicio 5
%Introducimos 2 numeros y nos devuelve su MCD

function  mcd =ejercicio5(x,y)
    tic;
    mayor=min(x,y); 
    mcd=0;
   for i=1:mayor
       if mod(x,i)==0 && mod(y,i)==0
          mcd=i;
       end
   end
    toc;
end
