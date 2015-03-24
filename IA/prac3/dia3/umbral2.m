%umbral(1)= umbral('00.bmp',1)  con REF=1
%umbral(2)= umbral('00.bmp',2)  con REF=2

function optimo = umbral2(imagen,umbral) %umbral es un vector de umbralim (que era una estructura)
    imagen = imread(imagen);
    %figure, imshow(imagen);
    h = imhist(imagen);
    %size(h)
    
    %para cambiar las REF!!
    % 1-> 1 - |x-y|
    % 2-> 1 - |x-y|^2
    % 3-> 1 - |x-y|^(1/2)
       
    %saber cuantos umbrales le pasas, para el for
    [fil, num_umb]=size(umbral);
    
    queREF=1;
    
    conjunto = zeros(1,256);
    %q=0:255;
    similitud= zeros(1,num_umb);
    
    
    for t=1:num_umb %for t=1 hasta todos los umbrales introducidos
        
        %size(q(1:t))
        %calcula la media de intensidades del fondo y del objeto
        %mb = sum(q(1:t+1).*h(1:t+1)') / sum(h(1:t+1)); 
        %traspuesta la primera para filas*columnas
        %mo = sum(q(t+2:256).*h(t+2:256)') / sum(h(t+2:255));
        
        
        for qaux=0:255
            %L-1=255
            %REF(x,y)=1-|x-y|
            
            if qaux <= umbral(t).t
                conjunto(qaux+1) = umbral(t).mb/255; %(t+1)?
            else
                conjunto(qaux+1) = umbral(t).mo/255;
            end   

           
        end
        %calcular similitud
        %M es media aritmetica
        similitud(t) = 1/255 * sum( h'.*REF(umbral(t).conjunto,conjunto,queREF));
        
        [maxima,umbral_optimo]=max(similitud);
        
        optimo=umbral(umbral_optimo).t;
        
        imagen(imagen<=optimo)=0;
        imagen(imagen>optimo)=255;
        
        imwrite(imagen,'imagen.jpg');
        imshow(imagen);
        
        
      
    end
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