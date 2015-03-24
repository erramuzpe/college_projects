%* ********************************************************

%** Metodo de Gauss Jordan                               **

%** por pasos                                       UdeG **

%**                              Maestria en Electronica **

%** Ing. Jesus Norato Valencia                           **

%** Materia: Metodos Numericos                           **

%** Maestro: M.C. J.Gilberto Mateos Suarez      5/Nov/99 **

%**********************************************************

clear;

clc;

fprintf('Dame la matriz aumentada\n\n');

f=input('Cuantas filas tiene la matriz: ');

c=input('Cuantas columnas tiene la matriz: ');
 
 

%***********************************************************

%** En los siguentes for anidados se da entrada a los     **

%** datos de la matriz aumentada, los cuales son dados    **

%** primero la columna 1, despues la 2 y asi sucesivamente**

%***********************************************************
 
 

for k=1:c

  for j=1:f

    fprintf('fila : %x\n',j)

    fprintf('columna : %x',k)

    r=input('Numero de esta fila y columna: ');

    a(j,k)=r;

    j=j+1;

  end

  k=k+1;

end

a

pause
 
 

%*********************************************************

%** En seguida se normalizan los pivotes y se hacen cero**

%** todos los numeros por debajo de ellos               **

%*********************************************************
 
 

for k=1:c-1

  a(k,:)=a(k,:)/a(k,k);

    for j=k+1:f

    a(j,:)=a(j,:)-a(k,:)*a(j,k);

    j=j+1;

    a

    pause

  end

  k=k+1;

  a

  pause

end
 
 

%******************************************************

%** En la siguiente seccion se hacen cero los numeros**

%** que estan por encima de la diagonal principal    **

%******************************************************
 
 

for k=f:-1:2

  for j=k-1:-1:1

    a(j,:)=a(j,:)-a(k,:)*a(j,k);

    j=j-1;

    a

    pause

  end

  k=k-1;

  a

  pause

end

fprintf('resultado\n');
  
