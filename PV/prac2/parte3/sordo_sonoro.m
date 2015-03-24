function v=sordo_sonoro(s,numsegmento);
% SORDO_SONORO determina si un segmento es sordo o es sonoro.
% numsegmento indica el numero de segmentos de 120 muestras
% posibles
% devuelve un vector v que contiene el periodo de pitch
v=1:numsegmento*120;
for i=1:numsegmento*120;
    v(i)=0;
end
 
for i=1:numsegmento-1
    segmento=seg_p1(s,i);
    segc=clipping(segmento);
    pitch=autoco(segc);
    z=1+(i-1)*120;
    for j=z:z+119
        v(j)=pitch;
    end
end