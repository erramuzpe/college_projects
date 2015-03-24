% abrir el fichero y reproducir
fich1=fopen('vege1850.8f','r');
[ficheroentrada,num]=fread(fich1,inf,'int16');
s=ficheroentrada;
%sound(s/max(s),8000);
 
s(1)=1; %evita errores!!
p=10;
numsegmento=floor(num/120);
 
% calcular coeficientes ak
% 10 * numsegmento
for i=1:numsegmento
    if (i==1)
        aktotal=funcak(seg(s,i),p);
    else
        aktotal=[aktotal,funcak(seg(s,i),p)]; % se concatena
    end
end

%size(aktotal)
 
% calcular excitacion Gu primer segmento
vectorcero=1:120;
for i=1:120
    vectorcero(i)=0;
end
Gu=excitacion(seg(s,1),vectorcero',aktotal(1:10),p);
 
% calcular excitacion Gu resto segmentos
for i=2:numsegmento
    z=((i-1)*10)+1;
    Gu=[Gu,excitacion(seg(s,i),seg(s,i-1),aktotal(z:z+9),p)]; % se concatena
end
 
% reconstrucción de la señal
sreconstruida=1:length(s);
for i=1:length(s)
    sreconstruida(i)=0;
end
ak=aktotal(1:10);
for i=11:length(Gu)
    sumatorio=0.0;
    for k=1:p
        sumatorio=(ak(k)*sreconstruida(i-k))+sumatorio;
    end
    sreconstruida(i)=sumatorio+Gu(i);
    
    % entra cada 120 muestras (1 segmento)
    % avanza el ak correspondiente
    if ((mod(i,120)==0) & (i~=length(Gu)))
        z=((i/120)*10)+1;
        ak=aktotal(z:z+9);
    end
end
 
% calculo del error
for z=1:length(s)
  error(z)=s(z)-sreconstruida(z);
end


% % representacion grafica de las señales
% subplot(2,1,1);
% plot(s);
% title('SEÑAL ORIGINAL');
% subplot(2,1,2);
% plot(sreconstruida);
% title('SEÑAL RECONSTRUIDA');
 sound(sreconstruida/max(sreconstruida),8000);
% pause
 
% representacion grafica segmento a segmento
for i=220 %numsegmento
  subplot(2,1,1);
  plot(seg(s,i));
  title(i);
  subplot(2,1,2);
  plot(seg(sreconstruida,i));
  title('SEGMENTO RECONSTRUIDO');
  pause
  subplot(1,1,1);
  plot (seg(error,i));
  title('ERROR COMETIDO');
  pause
end
