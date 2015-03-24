function [X,n] = leemuestras(fichero,nmues)
% Lee ficheros de codificacion
% Por defecto lee todas las muestras

f = fopen(fichero,'r');
if (nmues>0)
  X = fread(f,nmues,'int16');
else
  X = fread(f,Inf,'int16');
end
fclose(f);