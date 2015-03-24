function v=funcak(segmento,p)
% AK calcula los coeficientes ak de segmento 
ak=lpc(segmento,p);    
v=[ak(2:11)];
