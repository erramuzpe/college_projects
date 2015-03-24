function v=excitacion(s,z,ak,p)
% EXCITACION calcula la excitacion Gu del segmento de 120 muestras s
% devuelve el vector de excitacion v
% z es el segmento anterior de s
% ak es el vector de coeficientes ak de tamaño p
seg_auxiliar=z(111:120);
seg_auxiliar=[seg_auxiliar,s(1:10)];

% p muestras anteriores al segmento
for i=1:10
    sumatorio=0.0;
    for k=1:p      
        sumatorio=ak(k)*seg_auxiliar(i+10-k)+sumatorio;
    end
    v(i)=s(i)-sumatorio;
end
 
% el resto
for i=11:120
    sumatorio=0.0;
    for k=1:p      
        sumatorio=(ak(k)*s(i-k))+sumatorio;
    end
    v(i)=s(i)-sumatorio;
end
