function bienomal = prac4(carpetas,numeroimg,numvect)

    %Para hacer experimentos
    carpeta=carpetas;
    %0=normal
    %1=16 imagenes, 4xcara
    %2=12 imagenes, 3xcara
    %3=8 imagenes, 2xcara
    %4=4 imagenes, 1xcara
    
    %el numero maximo de 
    numvectprop=numvect;

    switch carpeta
        case 0
           numimag = 20;
           imagxcara = 5; 
        case 1
           numimag = 16;
           imagxcara = 4;      
        case 2
           numimag = 12;
           imagxcara = 3;  
        case 3
            numimag = 8;
           imagxcara = 2; 
        otherwise %case4
           numimag = 4;
           imagxcara = 1;
           
    end     
    caras=numimag/imagxcara;  

    %numimag = 20;
    %imagxcara = 5;
    %caras = numimag/imagxcara; (intentar siempre sea 4)
    


    %se coge una imagen cualquiera para saber su tamaño
    imagen = imread(strcat('./caras',num2str(carpeta),'/1.png'));
    [m, n] = size(imagen);
    imagenes = zeros(m*n, numimag);
    

    
    
    
    
    %Adquisición de datos: cada imagen 1 vector columna
    for i=1:numimag
        img = double(imread(strcat('./caras',num2str(carpeta),'/',num2str(i),'.png')));
        imagenes(:, i) = img(:);
    end
    %Tenemos 20 vectores de 10304x1 en imagenes
    
    %Calculamos la media de los vectores construidos
    media = mean(imagenes, 2);
    %size(med)
    A = zeros(m*n,numimag);
    %size(A)
    
    %'media' es 'psi' e 'imagenes(:,i) - media' es 'phi' en Φ = Γ − Ψ
    %A cada vector columna se le resta el vector media y se almacena en matriz de covarianza
    for i=1:numimag
        A(:,i) = imagenes(:,i) - media;
    end
    
    %Para calcular los 20 mayores valores y vect.propios
    C = A' * A;
    %vectores propios asociados a los valores propios de C
    [v,landa] = eig(C);
    
    %Se ordenan los vect. y val. propios may-men, porque luego, cuando
    %reduzcamos el numero de vect.props, cogeremos los de mayor valor
    sort(v,'descend');
    sort(landa,'descend');    
    
    
    
    %Calcular los 20 mayores vect.propios
    u = zeros(n*m,numimag);
    for i = 1:numvectprop
        u(:,i) = (A * v(:,i) / sqrt(landa(i,i)));
    end
    
    %Calculo de coordenadas ω = u'*Φ en la nueva base// A es el conjunto de Φ's
    w = u' * A;
    %El nuevo sistema de referencia (w) tiene 20 elementos
    
    %Para cada una de las 4 caras, se construye un vector de coordenadas media(ω) 
    mediaw = zeros(numimag,caras);
    for i=1:caras
        mediaw(:,i) = mean(w(:,imagxcara*(i-1)+1:imagxcara*i), 2);   %//rever
    end



    %los vectores propios son de todas las imagenes en conjunto
    %maximo vectores = numero de imagenes
    
    %%PARTE TESTEO
 


    %numeroimg = input('Introduce el numero de la imagen (100,200,300 o 400): ', 's');
    img = double(imread(strcat('./caras',num2str(carpeta),'/',num2str(numeroimg),'.png')));
        
    %Se transforma la imagen en un vector columna
    imagen = img(:);
        
    %Se le resta la media y se obtiene el vector Φ, multiplicando luego por u, para obtener ω
    wimagen = u' * (imagen - media);
        
    %argmin comprueba imagen por imagen cual es la que mas se parece
    for i=1:caras
	    diferente(i) = sum((mediaw(:,i) - wimagen).^2);
    end
    
    
    
    %
    %Reconstruccion imagen
    %
    %size(u*w)
    %size(media)
    imwrite(uint8(reshape(u*wimagen+media,m,n)),strcat('./carasprueba/','prob',num2str(numvect),'$',num2str(numimag),'$',num2str(numeroimg),'.png'));
    
    
    
        
    %I = FIND(X) returns the linear indices corresponding to 
    %the nonzero entries of the array X.  X may be a logical expression. 
    %En este caso, devuelve el indice de la persona con minima diferencia
    persona = find(diferente == min(diferente));
        

    %fprintf('Eres la persona nº %d\n', persona);

    if (num2str(numeroimg) == num2str(persona*100))
        %disp('Reconocido: CORRECTO');
        bienomal = 1;
    else
        %disp('No reconocido: FAIL');
        bienomal = 0;
    end
    
        
    %imshow(uint8(double(imread(['./caras',num2str(carpeta),'/',num2str(persona*100),'.png']))));
    
    
end









