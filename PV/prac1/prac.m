% abrir el fichero y reproducir
fich1=fopen('vege1850.8f','r');
[ficheroentrada,num]=fread(fich1,inf,'int16');
% plot(ficheroentrada)

%sound(ficheroentrada/max(ficheroentrada),8000);
% floor: redondeo hacia abajo
numsegmento=floor(num/120);
% 248 segmentos de 15 ms
 
% determinamos si la señal de voz es sonora o sorda
vectorpitch=sordo_sonoro(ficheroentrada,numsegmento);
% plot(vectorpitch) 

% si el segmento tiene un pitch igual a cero
% el segmento es sordo
% en caso contrario se almacena el valor de pitch
sordosonoro=0;
for i=1:numsegmento
    z=1+(i-1)*120;
    sordosonoro(i)=vectorpitch(z);
end
% plot(sordosonoro)
