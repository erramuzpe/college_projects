
%Definimos A
a = [1 4 0;0 2 3;3 3 7]

%con este "for" saco el valor mínimo de cada fila
for i = 1:3
    min(a(i,:))
end

%sacamos elemento de las columnas en orden descendente
for i = 1:3
    sort(a(:,i),'descend')
end

%sacamos elemento de las filas en orden ascendente
for i = 1:3
    sort(a(i,:))
end