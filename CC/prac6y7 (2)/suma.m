%-----*******PROGRAMA PARA REALIZAR LA SUMA DE DOS MATRICES C=A+B *****-------
% La condicion es que se debe de tener el mismo numero de filas y columnas
% en ambas matrices
clear, clc
disp('-----*******PROGRAMA PARA REALIZAR LA SUMA DE DOS MATRICES C=A+B *****-------')
fprintf('\n')
disp('CONDICION: Las matrices A y B, tienen que tener el mismo numero de filas y columnas')
fprintf('\n')
%Captura de los elementos de la matriz A
disp('Define el numero de filas y columnas de ambas matrices')
fprintf('\n')
f=input('Dame el numero de filas:');
fprintf('\n')
c=input('Dame el numero de columnas:');
disp('Introduce el valor de cada uno de los elementos de la matriz A')
for k=1:1:f
    for r=1:1:c
fprintf('Elemento A(%0.0f,%0.0f):\t ', k,r)
        A(k,r)=input('');
    end
end
disp('El valor de cada uno de los elementos de la matriz A son:')
A
% Captura de los elementos de la matriz B
disp('Introduce el valor de cada uno de los elementos de la matriz B')
for k=1:1:f
    for r=1:1:c
fprintf('Elemento B(%0.0f,%0.0f):\t ', k,r)
        B(k,r)=input('');
    end
end
disp('El valor de cada uno de los elementos de la matriz B son:')
B
%Seccion de la suma de matrices C=A+B
for k=1:1:f
    for r=1:1:c
        C(k,r)=A(k,r)+B(k,r);
    end
end
fprintf('La suma de las matrices A y B da como resultado una matriz C de %0.0f filas y %0.0f columnas):\n ', k,r)
C