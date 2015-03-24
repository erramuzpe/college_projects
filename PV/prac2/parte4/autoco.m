function pitch=autoco(s)
% AUTOCO mediante "center clipping"
% calcula la energia y el umbral
% sobre el rango de 20 a 120 muestras
r=s.*s;
energia=sum(r);
umbral=energia*30.0/100.0;
 
R=1:120;
for i=1:120
    R(i)=0;
end
 
for k=20:120
    r1=s(k+1:240);
    r2=s(1:240-k);
   
    r3=r1.*r2;
   
    R(k)=sum(r3);
end
 
[maximo,pitch]=max(R);
 
if maximo<umbral
    pitch=0;   
end