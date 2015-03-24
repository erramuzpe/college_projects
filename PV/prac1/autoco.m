function pitch=autoco(s)
% AUTOCO mediante "center clipping"
% calcula la energia y el umbral
% sobre el rango de 20 a 120 muestras

% cálculo de la energía
r=s.*s;
energia=sum(r);
 
% inicializar autoco a 0
R=1:120;
for i=1:120
    R(i)=0;
end
 
% el rango que abarca los posibles valores
% del periodo de pitch es 20:120.
% cálculo de R(k) // Está bien.
for k=20:120
    r1=s(k+1:240);
    r2=s(1:240-k);
   
    r3=r1.*r2;
   
    R(k)=sum(r3);
end
 
[maximo,pitch]=max(R);
umbral=energia*30.0/100.0;

% si el valor de pico cae por debajo del umbral
% el segmento se considera SORDO (0)
if maximo<umbral
    pitch=0;   
end
