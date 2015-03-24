


x = [1:7];
A = [0.1 0.3 0.7 1 0.6 0.2 0.1];

figure, plot(x, A, 'r')
hold on;

B = [0.2 0.8 1 0.6 0.4 0.3 0.1];
plot(x, B, 'b'), title('AUB en verde. AintersecB en negro')
hold on;

%A U B
plot(x,max(A,B),'g')
hold on;
%Comentar el hold on para que no salgan en la misma grafica

%A ? B
plot(x,min(A,B),'k')
hold on;
hold off;
%Comentar el hold on para que no salgan en la misma grafica

%C(B)
d=imcomplement(B)
plot(x,d,'k'),title('Complemento de B')

%C(A U B)
e=imcomplement(max(A,B))
plot(x,e,'k'),title('Complemento A U B')

%C(C(A) ? B)

f=imcomplement(min(imcomplement(A),B))
plot(x,f,'k'),title('Comp. del comp. A intersec. B')






