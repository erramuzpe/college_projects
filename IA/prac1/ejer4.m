%Utilizando la expresión del primer ejemplo, donde el conjunto E es el de
%personas adultas, da la función de pertenencia de los conjuntos joven y
%mayor, de manera que la suma de las pertenencias de cualquier edad en todos
%los conjuntos no sea mayor que 1.

x=[1:100];


adultos= 1./(1+((x-50)./10).^4);
plot(x,adultos,'g'), title('Adultos-Jovenes-Mayores')
hold on

jovenes=imcomplement(adultos);
jovenes(50:100)=0;
plot(jovenes,'r')
hold on


mayores=imcomplement(adultos);
mayores(1:50)=0;
plot(mayores,'k')
hold off