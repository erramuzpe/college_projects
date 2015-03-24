%ejer10 prac2

%definimos matriz a y matriz b
a=[3 0 1;0 5 2;0 0 7]
b=[3 0 9;7 3 0;0 4 3]


%Obtener en c la división elemento a elemento 'a' entre 'b'
a./b


%Calcular cuales de los elementos de c valen infinito
(a./b)== inf
%tambien con
isinf(a./b)

%Calcular cuales de los elementos de c valen NaN
isnan(a./b)