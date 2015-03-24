function [M,px,rank] = gauss_jordan(M)
% SEBASTIAN LOPEZ BURITICA 2007
% http://www.computrabajo.com.co/cvs/engsebastian
% M : Matriz a reducir, Matriz Reducida
% px: vector con los números de las filas independientes
% rank: rango de la matriz (número de filas diferentes de cero)

[f,d] = size(M);
c= 1;
rank= 0;
[px,p]=deal((1:f)');
while 1
if c ==f
%================================
% reduccion del error por multiplicaciones y sumas
a=max([f d])*norm(M)*eps;
M(find(abs(M)<a))=0;
%================================
pos=find(M(end,:)~=0);
if isempty(pos), break, end
[pos, p(c)]=deal(pos(1));
rank=c;
break
end

%================================
% hubicacion de la fila con el primer elemento diferente de cero
u=sum(abs(M(c:end, c:end)));
pos= find(u~=0)+c-1;
if isempty(pos), break, end
[pos, p(c)]=deal(pos(1));
pos2=find(M(c:end, pos)~=0)+c-1;
u= pos2;
%================================

%================================
% se hubica la fila con mayor norma para reducir el error por pivoteo
k=length(pos2);
for i=1:k, u(i)=norm(M(pos2(i),c:end)); end
u= find(u ==max(u));
u=u(1);
%================================

%================================
% para cambiar la posicion de las filas en caso de ser necesario
if c~=pos2(u)
M([c pos2(u)],:) = M([pos2(u) c],:);
px([c pos2(u)]) = px([pos2(u) c]);
if pos2(1)~=c
pos2(u)=[];
pos2=[c; pos2];
end
end
%================================

%================================
% Se hace la resta entre filas de arriba hacia abajo
if k >1
for i= 2:k
M(pos2(i),:) = M(pos2(i),:)-M(c,:).*(M(pos2(i),pos)/M(c,pos));
end
end
%================================
rank= c;
c= c+1;
end

%================================
% se termina de llevar la matriz a su forma escalonada reducida
if rank == 1
M(1,:) = M(1,:)/M(1,p(1));
elseif rank > 1
for i= 2:rank
for j= 1:(i-1)
M(j,:) = M(j,:)-M(i,:).*(M(j,p(i))/M(i,p(i)));
end
end
for i= 1:rank
M(i,:) = M(i,:)./M(i,p(i));
end
end
if rank < f
px((rank+1),end) = [];
end
%================================

%================================
% reduccion del error por multiplicaciones y sumas
a= max([f d])*norm(M)*eps;
M(find(abs(M) < a)) = 0;
