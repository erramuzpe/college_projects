
%Hice el ejercicio antes de que cambiara la primera función. La dejo así y
%luego en el 3º la cambio.
%Construimos las funciones
x = [1:10]

%F
f = (x-2)./x
plot(f,'r'), title('Funcion F')

%G
g = 2.^-x
plot(g,'g'), title('Funcion G')

%H
h = 1./(1+10.*(x-2).^2)
plot(h,'k'), title('Funcion H')


%C(F), C(H), C(G)
compf=imcomplement(f)
compg=imcomplement(g)
comph=imcomplement(h)


%F U G U H, F ? G ? H
maxi=max(max(f,h),g)
mini=min(min(f,h),g)

figure, plot(maxi, 'r'), title('Union rojo, interseccion negro')
hold on;
plot(mini,'k')

%F ? C(H), C(C(G) ? H), C(F U H)

a=min(f,comph)
plot(a), title('FintersecC(H)')

b=imcomplement(min(compg,h))
plot(b), title('C(C(G)intersecH)')

c=imcomplement(max(f,h))
plot(c), title('C(FUH)')


%Realiza los apartados a), b), c), utilizando la t-norma producto y la t-conorma suma probabilstica.
%(A*B) min
%(A+B)/A*B max

%F U G U H, F ? G ? H
maxi=((h+((f+g)./f.*g))./h.*((f+g)./f.*g))
mini=(f.*h.*g)

figure, plot(maxi, 'r'), title('Union rojo, interseccion negro')
hold on;
plot(mini,'k')

%F ? C(H), C(C(G) ? H), C(F U H)


a=f.*comph
plot(a), title('FintersecC(H)')

b=imcomplement(compg.*h)
plot(b), title('C(C(G)intersecH)')

c=imcomplement(((f+h)./f.*h))
plot(c), title('C(FUH)')

%Las graficas son practicamente iguales




















