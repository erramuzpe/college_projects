%Determinar los α-cortes en los conjuntos difusos F, G y H del ejercicio
%anterior para
%a) α = 0.2
%b) α = 0.5
%c) α = 0.9
%d) α = 1


%Construimos las funciones
x = [1:10]

%F
f = 1./(1+((x-5)./10).^4)
%G
g = 2.^(-x)
%H
h = 1./(1+10.*(x-2).^2)


disp('f - α corte = 0.2');
af=find(f >= 0.2)
disp('f - α corte = 0.5');
bf=find(f >= 0.5)
disp('f - α corte = 0.9');
cf=find(f >= 0.9)
disp('f - α corte = 1');
df=find(f >= 1)

disp('g - α corte = 0.2');
ag=find(g >= 0.2)
disp('g - α corte = 0.5');
bg=find(g >= 0.5)
disp('g - α corte = 0.9');
cg=find(g >= 0.9)
disp('g - α corte = 1');
dg=find(g >= 1)

disp('h - α corte = 0.2');
ah=find(h >= 0.2)
disp('h - α corte = 0.5');
bh=find(h >= 0.5)
disp('h - α corte = 0.9');
ch=find(h >= 0.9)
disp('h - α corte = 1');
dh=find(h >= 1)


   