function [umbralim,similitudant] = umbral(imagen)
    img = imread(imagen);
    %figure, imshow(imagen);
    h = imhist(img);
    size(h)
    
    conjunto = zeros(1,256);
    q=0:255;
    similitudant=0;
    
    
    for t=0:255 %for t=0 to L-1 do
        
        size(q(1:t))
        %calcula la media de intensidades del fondo y del objeto
        mb = sum(q(1:t).*h(1:t)') / sum(h(1:t)); %traspuesta la primera para filas*columnas
        mo = sum(q(t+1:255).*h(t+2:255)') / sum(h(t+1:255));
        
        
        for qaux=0:255
            %L-1=255
            %REF(x,y)=1-|x-y|
            
            if qaux <= t
                conjunto(t+1) = 1-abs((qaux/255)-(mb/255)); %(t+1)?
            else
                conjunto(t+1) = 1-abs((qaux/255)-(mo/255));
            end   

           
        end
        %calcular similitud
        %M es media aritmetica
        similitud = 1/255 * sum( (h(1:t+1)*1- abs(1-conjunto(t+1)) ));
        
        if similitudant<similitud
        	similitudant=similitud;
            umbralim=t;
        end
            
        
        
        
    end
    
    
end