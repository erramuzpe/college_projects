function c=sturm(p0,a,b)
% Calcula, mediante el método de Sturm, el número de raíces 
% distintas de un polinomio (p0) en el intervalo (a,b) sin contar multiplicidad.

% prec=precision o tolerancia
prec=10^(-8);

n=length(p0);

p(1,1:n)=p0;
g(1)=n;

%Calculamos la derivada
%de esta forma
p1=p0(1:n-1).*(n-1:-1:1);
p(2,1:n-1)=p1;
g(2)=n-1;
r=1;
cont=1;


while any(r)


   % deconv nos da cociente y resto de dos polinomios
   [q,r]=deconv(p(cont,1:g(cont)),p(cont+1,1:g(cont+1)));
   aux=find(abs(r)<prec);
   m=length(aux);
   r(aux)=zeros(1,m);
   ind=1;
   
   
   while abs(r(ind))==0 & ind<length(r)
      ind=ind+1;
   end
   
   
   g(cont+2)=length(r)-ind+1;
   p(cont+2,1:g(cont+2))=-r(ind:length(r));
   cont=cont+1;
   
   
end


p=p(1:cont,:);
g=g(1:cont);


for i=1:cont
   sa(i)=polyval(p(i,1:g(i)),a);
   sb(i)=polyval(p(i,1:g(i)),b);
end


sa=sa(find(sa));
sb=sb(find(sb));
ca=0;
cb=0;


for i=1:length(sa)-1
   if sa(i)*sa(i+1)<-eps
      ca=ca+1;
   end
end


for i=1:length(sb)-1
   if sb(i)*sb(i+1)<-eps
      cb=cb+1;
   end
end


c=ca-cb;   

