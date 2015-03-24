%vamos llamando a las funciones de los ejercicios realizados

%%Ejercicio1
v=[2 6 3 4 8 5];
ejercicio1(v);
ejercicio1f2(v);

%comparacion de tiempo
ejercicio1(rand(1,1000));
%el tiempo es:
%0.039800 seconds aprox.


ejercicio1f2(rand(1,1000));
%el tiempo es:
%0.029658 seconds aprox



%%Ejercicio3
w=[8 3 1 -1 2 1 4 6 5 3 6 7];
ejercicio3(w);


%%Ejercicio5

%comparacion de tiempo
%con "round(800000*rand+100000)" consigo num.aleat. entre 100000 y 900000
%realmente, no me parece justo comparar dos numeros aleatorios, el calculo del mcd puede variar mucho.

ejercicio5(round(800000*rand+100000),round(800000*rand+100000));
%el tiempo es:
%31.39641 seconds aprox.

ejercicio5f2(round(800000*rand+100000),round(800000*rand+100000));
%el tiempo es:
%125 seconds aprox. (aunque este segundo es más eficiente...)

%%Ejercicio 7

p= [1 3 5;2 8 6; 4 1 0];
q= [2 2 5;2 3 4; 6 1 7];
ejercicio7(p,q);



