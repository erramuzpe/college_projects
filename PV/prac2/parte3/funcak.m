function v=funcak(segmento,p)
% AK calcula los coeficientes ak de segmento 
ak=lpc(segmento,p);    
for z=1:p+1
    ak(z)=-1*ak(z);
end
v=[ak(2:11)];