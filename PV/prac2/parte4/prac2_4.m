% abrir el fichero y reproducir
fich1=fopen('euge0019.8f','r');
%vege1850 -> masculino
[ficheroentrada,num]=fread(fich1,inf,'int16');
% plot(ficheroentrada)
sound(ficheroentrada/max(ficheroentrada),8000);
s=ficheroentrada;
s(1)=1; %evita errores!!

% floor: redondeo hacia abajo
numsegmento=floor(num/120);

% determinamos si la se�al de voz es sonora o sorda
% segun el algoritmo implementado en la practica 1
vectorpitch=sordo_sonoro(s,numsegmento);
 
% si el segmento tiene un pitch igual a cero
% diremos que el segmento es sordo
% en caso contrario se almacena el valor de pitch
sordosonoro=0;
for i=1:numsegmento
    z=1+(i-1)*120;
    sordosonoro(i)=vectorpitch(z);
end

% Modificar a antojo
%sordosonoro=floor(sordosonoro*2);

%Para sonar robotizado
for i=1:numsegmento
    if sordosonoro(i)~=0
        sordosonoro(i)=50;
    end
end

p=10;
% calcular coeficientes ak
for i=1:numsegmento-1
    if (i==1)
        aktotal=funcak(seg_p1(s,i),p);
    else
        aktotal=[aktotal,funcak(seg_p1(s,i),p)];
    end
end
 
% calcular excitacion Gu primer segmento
% y la energia Ee del primer segmento
Ee=0;
vectorcero=1:120;
for i=1:120
    vectorcero(i)=0;
end
temp=excitacion(seg_p1(s,1),vectorcero',aktotal(1:10),p);
Gu=temp;
Ee(1)=calcular_energia(temp);
 
% calcular excitacion Gu del resto de segmentos
% y la energia Ee del resto de segmentos
for i=2:numsegmento-1
    z=((i-1)*10)+1;
    temp=excitacion(seg_p1(s,i),seg_p1(s,i-1),aktotal(z:z+9),p);
    Gu=[Gu,temp];
    Ee(i)=calcular_energia(temp);
end
 
% generar la excitacion simplificada
clear('Gusimplificada');
clear('G');
for i=1:numsegmento-1
 
    % segmento sordo
    if (sordosonoro(i)==0)
        for j=1:120
            u(j)=randn;
        end
        Eu=calcular_energia(u);
        G=sqrt(Ee(i)/Eu);
        if (exist('Gusimplificada')==0)
            Gusimplificada=G*u;
        else
            Gusimplificada=[Gusimplificada,G*u];           
        end
 
    % segmento sonoro   
    else
        for j=1:120
            u(j)=0;
        end
        L=0;
        z=1;
        while (z<=120)
            u(z)=1;
            L=L+1;
            z=z+sordosonoro(i);
        end
        G=sqrt(Ee(i)/L);
        if (exist('Gusimplificada')==0)
            Gusimplificada=G*u;
        else
            Gusimplificada=[Gusimplificada,G*u];           
        end
    end
end
 
% se genera la se�al de voz a partir de la se�al de
% excitacion simplificada
sreconstruida=1:length(s);
for i=1:length(s)
    sreconstruida(i)=0;
end
ak=aktotal(1:10);
for i=11:length(Gusimplificada)
    sumatorio=0.0;
    for k=1:p
        sumatorio=(ak(k)*sreconstruida(i-k))+sumatorio;
    end
    sreconstruida(i)=sumatorio+Gusimplificada(i);
    if ((mod(i,120)==0) & (i~=length(Gusimplificada)))
        z=((i/120)*10)+1;
        ak=aktotal(z:z+9);
    end
end
 
% calculo del error
for z=1:length(s)
  error(z)=s(z)-sreconstruida(z);
end
 
% representacion grafica de las se�ales
% subplot(2,1,1);
% plot(s);
% title('SE�AL ORIGINAL');
% subplot(2,1,2);
% plot(sreconstruida);
% title('SE�AL RECONSTRUIDA');
  sound(sreconstruida/max(sreconstruida),8000);
% pause
%  
% representacion grafica segmento a segmento
% for i=220 %numsegmento
%   subplot(2,1,1);
%   plot(seg_p1(s,i));
%   title(i);
%   subplot(2,1,2);
%   plot(seg_p1(sreconstruida,i));
%   title('SEGMENTO RECONSTRUIDO');
%   pause
%   subplot(1,1,1);
%   plot (seg_p1(error,i));
%   title('ERROR COMETIDO');
%   pause
% end
