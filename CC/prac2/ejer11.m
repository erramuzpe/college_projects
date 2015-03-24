%ejer11 prac2

%Crear los vectores a, b y c tal que

%a contenga los números naturales desde 0 hasta 30 tomados de 5 en 5;
a=0:+5:30

%b contenga los números naturales del 21 al 27.
b=21:27

%c contenga 7 números aleatorios entre 10 y 35.
c=25*rand(1,7)+10
%para redondear a enteros
c=round(25*rand(1,7)+10)


%Mostrar en una sola gráfica los tres vectores
%a estén representados por cuadrados de color verde unidos por líneas a
%trazos
%b estén representados por estrellas de 5 puntos de color rojo unidas por
%líneas contínuas;
%los elementos de c estén representados triángulos apuntando a la izquierda de color magenta
%unidos por líneas punteadas.

plot(a,'--ks', 'LineWidth',2, 'MarkerEdgeColor','g', 'MarkerFaceColor', 'g','MarkerSize',10)
hold on
plot(b,'-kp', 'LineWidth',2, 'MarkerEdgeColor','r', 'MarkerFaceColor', 'r','MarkerSize',10)
hold on
plot(c,':k<', 'LineWidth',2, 'MarkerEdgeColor','m', 'MarkerFaceColor', 'm','MarkerSize',10)
hold off




