function [fichero,num] = leer(numero,carpeta) 


fich=fopen(strcat('./',carpeta,'/',num2str(numero),'.x'));

[fichero,num]=fread(fich,inf,'int16');
