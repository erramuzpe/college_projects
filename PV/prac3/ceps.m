function [ cepstrum ] = ceps( ak )

[i,j]=size(ak);
p=12;

cepstrum(1)=-ak(1);
for n=2:j  %el ak es size 10
    cepstrum(n)=-ak(n);
    for k=1:n-1
        cepstrum(n)=cepstrum(n)-(1-k/n)*ak(k)*cepstrum(n-k);
    end;
end;

for n=j+1:p
    cepstrum(n)=0;
end

