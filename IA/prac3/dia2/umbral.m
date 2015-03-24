function [umbralim,similitudant] = umbral(imagen)
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
    similitudant=0;
    
    
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

           
        end
        %calcular similitud
        %M es media aritmetica
        similitud = 1/255 * sum( h'.*REF(1,conjunto,queREF));
        
        if similitudant<similitud
        	similitudant=similitud;
            umbralim.t=t;
            umbralim.conjunto=conjunto;
            umbralim.mb=mb;
            umbralim.mo=mo;
        end
        
      
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