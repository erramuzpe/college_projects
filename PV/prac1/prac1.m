%PRAC1 PV

X = leemuestras('aage3201.8f',0); %En X esta la muestra a analizar
%X = X';



[M,N]= size(X);
i=fix(M/120);
%i=2*i-1;
muestra = zeros(i,240);
%size(muestra)
j=1;


%Extraemos muestras de 240 cada 120 (se solapan)
for i=1:120:M-240
    muestra(j,:) = X(i:i+239);
    j=j+1;
end

%para comprobar que las muestras se solapan
% muestra(123,121) = muestra(124,1) // FUNCIONA
[M,N]=size(muestra);

clipping = min(max(max(muestra(1:79,:))),max(max(muestra(M-79:M,:))));

%REVISAR ESTO, ESTA MAL EL PLANTEAMIENTO
    


