function v=seg(s,x)
% SEG segmenta el vector s
% devuelve el vector numero x de 256 muestras
% solapado con el anterior 128 muestras
a=1+(x-1)*128;
b=a+255;
v=s(a:b);
