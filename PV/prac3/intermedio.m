function indice = intermedio(numero) 

fich1=fopen(strcat('./recvoz/',numero,'.x20'));
fich2=fopen(strcat('./recvoz/',numero,'.x21'));
fich3=fopen(strcat('./recvoz/',numero,'.x22'));

[ficheroentrada1,num]=fread(fich1,inf,'int16');
[ficheroentrada2,num]=fread(fich2,inf,'int16');
[ficheroentrada3,num]=fread(fich3,inf,'int16');

%sound(ficheroentrada1/max(ficheroentrada1),8000);
%sound(ficheroentrada2/max(ficheroentrada2),8000);
%sound(ficheroentrada3/max(ficheroentrada3),8000);

[m1,n]=size(ficheroentrada1);
[m2,n]=size(ficheroentrada2);
[m3,n]=size(ficheroentrada3);

mediana = median([m1 m2 m3]);
indice = find([m1 m2 m3]==mediana,1);



