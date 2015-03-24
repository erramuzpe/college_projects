function v=seg(s,x)
% SEG segmenta el vector s
% devuelve el vector numero x de 120 muestras
% x esta comprendido entre 1 y n
a=1+(x-1)*120;
b=a+119;
v=s(a:b);
