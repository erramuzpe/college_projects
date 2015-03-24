

% variables
p=10;
% X segmentos de 128 muestras

% Abrir y calcular ak y cepstrum para patron
patrones = cell(10);
akpatrones = cell(10);
cepspatrones = cell(10);
for i=1:10
    [patrones{i},indice(i)]=leer(i-1,'patron');
    
    numsegmento(i)=floor(indice(i)/128);
    % calcular coeficientes ak
    for j=1:numsegmento(i)-1
        if (j==1)
            aktotal=funcak(seg(patrones{i},j),p);
        else
            aktotal=[aktotal,funcak(seg(patrones{i},j),p)];
        end
    end
    akpatrones{i}= aktotal;
    
    % calcular ceptrum para cada segmentos
    for k=1:numsegmento(i)-1
        z=((k-1)*10)+1;
           if (k==1)
                cepstrum=ceps(aktotal(z:z+9));
            else
                cepstrum=[cepstrum,ceps(aktotal(z:z+9))];
            end
    end
    cepspatrones{i}= cepstrum;
end


% Abrir y calcular ak y cepstrum para test
tests = cell(20);
aktests = cell(20);
cepstests = cell(20);
for i=1:20
    [tests{i},indice(i)]=leer(i,'test');
    
    numsegmento(i)=floor(indice(i)/128);
    % calcular coeficientes ak
    for j=1:numsegmento(i)-1
        if (j==1)
            aktotal=funcak(seg(tests{i},j),p);
        else
            aktotal=[aktotal,funcak(seg(tests{i},j),p)];
        end
    end
    aktests{i}= aktotal;
    
    % calcular ceptrum para cada segmentos
    for k=1:numsegmento(i)-1
        z=((k-1)*10)+1;
           if (k==1)
                cepstrum=ceps(aktotal(z:z+9));
            else
                cepstrum=[cepstrum,ceps(aktotal(z:z+9))];
            end
    end
    cepstests{i}= cepstrum;
end




for j=1:20
    for i=1:10
        diferente(i)= DTW(cepspatrones{i},cepstests{j});
        indice = find(diferente == min(diferente));
        numero(j) = indice-1;
    end
end
numero

