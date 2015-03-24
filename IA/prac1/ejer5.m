%ejer 5


x=[1:100];
adultos= 1./(1+((x-50)./10).^4);


jovenes=imcomplement(adultos);
jovenes(50:100)=0;
plot(x,jovenes,'g'), title('Joven - Muy Joven')
hold on
muy_joven= jovenes.^2;
plot(muy_joven,'r')
hold off

mayores=imcomplement(adultos);
mayores(1:50)=0;
plot(mayores,'k'), title('Mayores-Bastante Mayor')
hold on
bastante_mayor=mayores.^(1/2);
plot(bastante_mayor,'g')
hold off


muy_adulto=adultos.^2;
no_muy_adulto=imcomplement(muy_adulto);
ligeramente_adulto=min(muy_adulto,no_muy_adulto);
plot(x,muy_adulto,'g'), title('Muy Adulto- No muy adulto - Ligeramente adulto')
hold on
plot(x,no_muy_adulto,'r')
hold on
plot(x,ligeramente_adulto,'k')
hold off

