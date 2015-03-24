%Dibujar en una gráfica la función 'x4-5x3+4x2+2' en el dominio x ? [-1,6]

x=linspace(-1,6,2000)
x=-1:.01:6;

a= x.^4-5.*(x.^3)+4.*(x.^2)+2

plot(x,a)