function v=sordo_sonoro(s,numsegmento);
% SORDO_SONORO determina si un segmento es sordo o es sonoro.
% numsegmento indica el numero de segmentos de 120 muestras
% posibles
% devuelve un vector v que contiene el periodo de pitch
v=1:numsegmento*120;
%Inicializar v a 0
for i=1:numsegmento*120;
    v(i)=0;
end
 
% segmento a segmento
for i=1:numsegmento-1
    % consguimos el segmento actual 
    segmento=seg(s,i);
    % se le hace el clipping
%     if (i==100)
%        plot(segmento);
%     end
    
    segclip=clipping(segmento);
    
    %Para comprobar que clipping funciona bien.
    if (i==100)
       plot(segclip);
       hold all;
       plot(segmento);
    end


    pitch=autoco(segclip);
    z=1+(i-1)*120;
    for j=z:z+119
        v(j)=pitch;
    end
end
