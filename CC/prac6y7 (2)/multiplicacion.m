%-----*******PROGRAMA PARA REALIZAR LA MULTIPLICACION DE DOS MATRICES C=A*B *****-------
% La condicion es que el numero de columnas de la primera, debe de ser
% igual al numero de filas de la segunda
clear, clc
disp('-----*******PROGRAMA PARA REALIZAR EL PRODUCTO DE DOS MATRICES C=A*B *****-------')
fprintf('\n')
disp('CONDICION: El numero de columnas de la primera, debe de ser igual al numero de filas de la segunda')
fprintf('\n')
%Captura de las dimensiones de las matrices.
fprintf('\n')
f=input('Dame el numero de filas de la matriz A:');
fprintf('\n')
cf=input('Dame el numero de columnas de la matriz A y de filas de la matriz B:');
fprintf('\n')
c=input('Dame el numero de columnas de la matriz B');
disp('Introduce el valor de cada uno de los elementos de la matriz A')
for k=1:1:f
    for r=1:1:cf
fprintf('Elemento A(%0.0f,%0.0f):\t ', k,r)
        A(k,r)=input('');
    end
end
disp('El valor de cada uno de los elementos de la matriz A son:')
A
% Captura de los elementos de la matriz B
disp('Introduce el valor de cada uno de los elementos de la matriz B')
for k=1:1:cf
    for r=1:1:c
fprintf('Elemento B(%0.0f,%0.0f):\t ', k,r)
        B(k,r)=input('');
    end
end
disp('El valor de cada uno de los elementos de la matriz B son:')
B
%Seccion de producto de matrices C=A*B
 C=zeros(f,c);
for k=1:1:f
    for r=1:1:c
        for p=1:1:cf
          C(k,r)=C(k,r)+(A(k,p)*B(p,r));
     end
 end
end
fprintf('El producto de de las matrices A y B da como resultado una matriz C de %0.0f filas y %0.0f columnas):\n ', k,r)
C