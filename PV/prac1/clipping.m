function seg=clipping(s)
% CLIPPING calcula el minimo de los valores
% maximos absolutos en las primeras y las
% ultimas 80 muestras del segmento.
% los valores del segmento que queden por
% debajo del valor obtenido se hacen cero
 
% primeras y últimas 80 muestras del segmento
a1=s(1:80);
a2=s(161:240);
 
seg=s;
 
a1=abs(a1);
a2=abs(a2);
 
b1=max(a1);
b2=max(a2);
 
v=[b1 b2];
% mínimo de los máximos valores absolutos
resul=min(v);
resul=resul*68.0/100.0; % el 68%

% resul es el umbral, sólo se guarda 
% lo que queda por encima y por debajo
for i=1:240
    if seg(i)>0
        if seg(i)<resul
            seg(i)=0;
        else
            seg(i)=seg(i)-resul;
        end
    else
        if seg(i)>-resul
            seg(i)=0;
        else
            seg(i)=seg(i)+resul;
        end
    end
end