function umbral = umbral3(imagen,alpha)
    img = imread(imagen);
    %figure, imshow(imagen);
    h = imhist(img);
    %size(h)
    
    %para cambiar las REF!!
    % 1->1 - |x-y|
    % 2->1 - |x-y|^2
    % 3->1 - |x-y|^(1/2)
       
    queREF=1;
    
    conjunto = zeros(1,256);
    q=0:255;
    qt=zeros(2
    ,255);
    entropia=zeros(1,255)
    
    
    for t=0:255 %for t=0 to L-1 do
        
        %size(q(1:t))
        %calcula la media de intensidades del fondo y del objeto
        mb = sum(q(1:t+1).*h(1:t+1)') / sum(h(1:t+1)); 
        %traspuesta la primera para filas*columnas
        mo = sum(q(t+2:256).*h(t+2:256)') / sum(h(t+2:255));
        
        
        for qaux=0:255
            %L-1=255
            %REF(x,y)=1-|x-y|
            
            if qaux <= t
                conjunto(qaux+1) = REF(qaux/255,mb/255,queREF); %(t+1)?
            else
                conjunto(qaux+1) = REF(qaux/255,mo/255,queREF);
            end   

            
        qt(qaux)=[conjunto.^alpha conjunto.^(1/alpha)];
            
           
        end
        %calcular similitud
        %M es media aritmetica
        %similitud = 1/255 * sum( h'.*REF(1,conjunto,queREF));
        
        
        
        entropia(t) = 1/sum(h)*sum(h'.*(qt(2,:)-qt(1,:)));
             
      
    end
    
    [ent,umbral]=min(entropia);
    %con ent no hacemos nada
    
    
    imagen(imagen<=optimo)=0;
    imagen(imagen>optimo)=255;
        
    imwrite(imagen,'imagen.jpg');
    imshow(imagen);
    
end

    
    
function res=REF(x,y,queREF)
    if (queREF<=1) % 1 - |x-y|
        res=1-abs(x-y);
    elseif (queREF==2) % 1 - |x-y|^2
       res=1-abs(x-y).^2;
    elseif (queREF>=3) % 1 - |x-y|^(1/2)
       res=1-abs(x-y).^(1/2);
    end
end