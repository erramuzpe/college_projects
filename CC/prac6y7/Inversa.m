%-----*******PROGRAMA PARA OBTENER LA INVERSA DE UNA MATRIZ DE 3X3 *****-------
clear, clc
disp('-----*******PROGRAMA PARA OBTENER LA INVERSA DE UNA MATRIZ DE 3X3 *****-------')
fprintf('\n')
disp('CAPTURA DE VALORES')
fprintf('\n')
disp('Introduce el valor de cada uno de los elementos de la matriz')
for k=1:1:3
    for r=1:1:3
fprintf('Elemento A(%0.0f,%0.0f):\t ', k,r)
        A(k,r)=input('');
    end
end
disp('El valor de cada uno de los elementos de la matriz son:')
A
B=zeros(3,3);
C=zeros(3,3);
%Calculo de menores
B(1,1)=(A(2,2)*A(3,3))-(A(3,2)*A(2,3));
B(2,1)=(A(1,2)*A(3,3))-(A(3,2)*A(1,3));
B(3,1)=(A(1,2)*A(2,3))-(A(2,2)*A(1,3));
B(1,2)=(A(2,1)*A(3,3))-(A(3,1)*A(2,3));
B(2,2)=(A(1,1)*A(3,3))-(A(3,1)*A(1,3));
B(3,2)=(A(1,1)*A(2,3))-(A(2,1)*A(1,3));
B(1,3)=(A(2,1)*A(3,2))-(A(3,1)*A(2,2));
B(2,3)=(A(1,1)*A(3,2))-(A(3,1)*A(1,2));
B(3,3)=(A(1,1)*A(2,2))-(A(2,1)*A(1,2));
%Calculo de cofactores
for k=1:1:3
    for r=1:1:3
            C(k,r)=((-1)^(k+r))*B(k,r);
        end
    
    end
     for k=1:1:3
       for r=1:1:3
            B(k,r)=C(r,k);
        end
    end
DA=0;
for i=1:1:3
    DA=DA+(A(1,i)*C(1,i));
end


for k=1:1:3
       for r=1:1:3
            C(k,r)=B(k,r)/DA;
        end
    end


fprintf('La inversa de la Matriz que introdujo es:')
C