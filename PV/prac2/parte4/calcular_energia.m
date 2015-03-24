function a=calcular_energia(s)
% CALCULAR_ENERGIA calcula la energia del
% segmento s de 120 muestras

sumatorio=0.0;
for n=1:120
    sumatorio=sumatorio+(s(n)*s(n));
end
a=sumatorio/120;
