%%daniel.paternain@unavarra.es
% Asier Erramuzpe Practica 2 Gradiente (segundo metodo)

% 'c' es de entrada
%  R' = A - B
%  Q = R - R'. si 0, ya esta

%  Sino, calcular iter+1 //complicado

%  Comprobar si iter+1-iter < tol (tol es de entrada)

function salida = gradiente2(imagen, c, alpha, tol)


    tic
	%Leer imagenes y minimizarlas
	R = imread(imagen);
	R = double(R);
	R = R./255;
	[fila,col] = size(R);
	j = 0;
	%alpha = 0.005 , por parametro o inicializado aqui
	%A y B son aleatorios al principio
	A = rand(c,fila);
	B = rand(c,col);



	Rgor = zeros(fila, col);
	%MinMax
	for x=1:fila
		for y=1:col
		    Rgor(x,y) = max(min(A(:, x),B(:,y)));
		end
	end

	errorfin = sum(sum((R-Rgor).^2));
	errorini = inf;
    fprintf('Iteración %d: Error: %s\n',j, num2str(errorfin));
	
	%Criterio de parada tol
	while (errorini-errorfin >= tol)

		j=j+1;
		errorini = errorfin;
		Aant=A;
		Bant=B;

		%Calculo de iter+1
		for i=1:c
			%Calcular A(c) de iter+1
			for x=1:fila
				suma=0;
				for y=1:col
					%Txungo
                    suma = suma + (R(x,y) - max(min(Aant(:, x), Bant(:, y)))) * (Aant(i,x) == Rgor(x,y));
				end
				A(i,x)=Aant(i,x)+2*alpha*suma;
			end
		end
			
		for i=1:c
			%Calcular B(c) de iter+1
			for y=1:col
				suma=0;
				for x=1:fila
					%Txungo
                    suma = suma + (R(x,y) - max(min(Aant(:, x), Bant(:, y)))) *  (Bant(i,y) == Rgor(x,y));
				end
				B(i,y)=Bant(i,y)+2*alpha*suma;
			end
		end		


		%MinMax
		for x=1:fila
			for y=1:col
			    Rgor(x,y) = max(min(A(:, x),B(:,y)));
			end
        end
        
		errorfin = sum(sum((R-Rgor).^2));
        fprintf('Iteración: %d  diferencia  %s\n ', j,num2str(errorini-errorfin));
        
        
	end




	%Al final
	imshow(uint8(Rgor.*255));
	imwrite(uint8(Rgor.*255),strcat('grad2iter',num2str(j),'c',num2str(c),imagen));
    toc

end





