

num = char('cero','uno','dos','tres','cuatro','cinco','seis','siete','ocho','nueve');

for i=1:10
%     if numero == 0
%         num='cero';
%     end
%     
        indice(i) = intermedio(num(i,:));
        fprintf('Para el numero %s el fich. de long intermedia es: x2%d\n',num(i,:),indice(i)-1);
end