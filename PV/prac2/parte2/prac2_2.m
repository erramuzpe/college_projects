% primero prac2_1.m
 
% inicializacion

h=1:length(s);
for i=1:length(s)
    h(i)=0;
end
 
% calcular la respuesta impulso
% la respuesta impulso vale 1 para la primera y 0 para anteriores
h(1)=1;
ak=aktotal(1:10);
for i=2:length(h)
    sumatorio=0.0;
    for k=1:p
        if ((i-k>0))
            sumatorio=ak(k)*h(i-k)+sumatorio;
        end
    end
    if (mod((i-1),120)==0)
        h(i)=sumatorio+1;
    else
        h(i)=sumatorio;
    end
	
    % mientras no final, pasamos al siguiente segmento.
    if ((mod(i,120)==0) & (i~=length(Gu)))
        z=((i/120)*10)+1;
        ak=aktotal(z:z+9);
    end
end
 
% representacion grafica del espectro de la señal
% del espectro de la respuesta impulso y del
% espectro de la señal de excitacion Gu
for i=195  %numsegmento
    subplot(3,1,1);
    calc_espectro(seg(s,i));
    title(i);
    subplot(3,1,2);
    calc_espectro(seg(h,i));
    subplot(3,1,3);
    calc_espectro(seg(Gu,i));
    pause
end
