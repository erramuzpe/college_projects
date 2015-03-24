function v=seg(s,x)
% SEG segmenta el vector s
% devuelve el vector numero x de 240 muestras
% solapado con el anterior 120 muestras
a=1+(x-1)*120;
b=a+239;
v=s(a:b);