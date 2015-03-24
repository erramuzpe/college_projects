%ejer 7


cerca(1:4)=1;
cerca(5:15)=0;

%%a
lejos(1:10)=0;
lejos(11:15)=1;

plot(cerca,'g'), title('DISTANCIA')
hold on
plot(lejos,'r')
legend('Cerca','Lejos')
hold off

%%b
%Todas las funciones estas definidas en scripts
%nomuycerca = c = 1-cerca(x).^2;


clear all;

grado = nomuycerca(4.5) + lejos(10.7) - nomuycerca(4.5) * lejos(10.7)

%grado = 0.925