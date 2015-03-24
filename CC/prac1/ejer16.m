%Calcular de dos formas distintas el numero de elementos de una matriz
%Vamos a usar una matriz 3x4

a = [2 1 5 -1;4 -3 2 -1;3 7 -3 4]

%El resultado debe ser 12

%Funcion por defecto en Matlab
numel(a)

%El numero de filas/columnas mas alto por el mas bajo
length(a)*min(size(a))