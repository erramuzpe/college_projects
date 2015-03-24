%-----*******++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ *****-------
%-----*******++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ *****-------
%-----*******     IIIIIIIIIII                      PPPPPP                  NN        NN                        *****-------
%-----*******         III                          PP    PP                NNN       NN                        *****-------
%-----*******         III                          PP   PP                 NN NN     NN                        *****-------
%-----*******         III                          PP PP                   NN   NN   NN                        *****-------
%-----*******         III                          PP                      NN     NN NN                         *****-------
%-----*******     IIIIIIIIIII                      PP                      NN        NN                         *****-------
%-----*******++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ *****-------
%-----*******++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ *****-------
%-----*******++++++++++++++++++++++                  JRH         ++++++++++++++++++++++++++++++++++++++++++++++++ *****-------
%-----*******PROGRAMA PARA REALIZAR LA SOLUCION DE UN SISTEMA DE ECUACIONES DE N INCOGNITAS METODO DE GAUS-JORDAN *****-------
clear, clc
disp('-----*******PROGRAMA PARA REALIZAR LA SOLUCION DE UN SISTEMA DE ECUACIONES POR GAUS-JORDAN *****-------')
fprintf('\n')

n=input('Introduce el numero de incognitas de tu sistema:');%Aqui se define el numero de ecuaciones del sistema
for z=1:1:n
    fprintf('\n')
    %Llenado de datos de la matriz
fprintf('Coeficientes de la ecuacion %0.0f\n',z)
    for x=1:1:n
        fprintf('\n')
fprintf('Coeficiente %0.0f:  ',x)
A(z,x)=input('');
    end
    fprintf('\n')
fprintf('Introduce el valor de la igualdad de la ecuacion %0.0f:  ',z)    
     A(z,n+1)=input('');
end
%Despliegue de los valores introducidos
disp('EL ARREGLO DE LA MATRIZ AUMENTADA PARA APLICAR GAUS-JORDAN ES:')
A
%Algoritmo para solucion por Gaus-Jordan
for k=1:n
     A(k,:)=A(k,:)/A(k,k);
     j=1;
  for i=1:n 
     if i==k
            else
     A(i,:)=A(i,:)-(A(k,:)*A(i,k));
             end
        end
    end
A
fprintf('La matriz solucion del sistema de ecuaciones es:\n')
for k=1:1:n
    d=A(k,(n+1));
fprintf('X%f:    %f \n',k,d)
end