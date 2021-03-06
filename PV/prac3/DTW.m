function dist = DTW(t,r)

% adapto para poder manipular mejor, en cada columna, ceps de 1 seg.
[m,n]=size(t);
n=n/12;
for i=1:n
    a(:,i)=t((((i-1)*12)+1):(i*12))';
end

% adapto para poder manipular mejor, en cada columna, ceps de 1 seg.
[m,n]=size(r);
n=n/12;
for i=1:n
    b(:,i)=r((((i-1)*12)+1):(i*12))';
end

t=a';
r=b';

n = size(t,1);
m = size(r,1);


d=zeros(n,m);

% primer punto
d(1,1)=norm(t(1,:)-r(1,:));
% primera fila
for j=2:m
    d(1,j)=d(1,j-1)+norm(t(1,:)-r(j,:));
end

% resto de filas
for i=2:n
    %el primero de la fila n
    d(i,1)=d(i-1,1)+norm(t(i,:)-r(1,:));
    %resto sabiendo sus adyacentes
    for j=2:m
        d(i,j)=min([d(i-1,j) d(i,j-1) d(i-1,j-1)])+norm(t(i,:)-r(j,:));
    end
end
dist=d(n,m); % /(n+m)
end

