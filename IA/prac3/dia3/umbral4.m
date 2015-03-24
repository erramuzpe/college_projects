function umbralim = umbral4(imagen,queREF)
    img = imread(imagen);
    %figure, imshow(imagen);
    h = imhist(img);
    %size(h)
    
    %para cambiar las REF!!
    % 1->1 - |x-y|
    % 2->1 - |x-y|^2
    % 3->1 - |x-y|^(1/2)
       
    %queREF=1;
    
    conjuntoOt = zeros(1,256);
    conjuntoBt = zeros(1,256);
    q=0:255;
    qt= zeros(1,256);
    qt2= zeros(1,256);
    entropia= zeros(1,255);
    
    
    for t=0:255 %for t=0 to L-1 do
        
        %size(q(1:t))
        %calcula la media de intensidades del fondo y del objeto
        mb = sum(q(1:t+1).*h(1:t+1)') / sum(h(1:t+1)); 
        %traspuesta la primera para filas*columnas
        mo = sum(q(t+2:256).*h(t+2:256)') / sum(h(t+2:255));
        
        
        for qaux=0:255
            %L-1=255
            %REF(x,y)=1-|x-y|
            
            %conjunto BT
            conjuntoBt(qaux+1) = REF(qaux/255,mb/255,queREF); %(t+1)?
            %conjunto OT
            conjuntoOt(qaux+1) = REF(qaux/255,mo/255,queREF);
             
            
            %calcular conjuntos intervalo-valorados
            qt(qaux+1)= (igno(0.5,0.5)-igno(conjuntoBt(qaux+1),conjuntoOt(qaux+1)) ) ; %intervalovalorado 1
            qt2(qaux+1) = (igno(0.5,0.5) ); %intervalovalorado 2
           
        end
        
        %M es media aritmetica
        
        entropia(t+1) = 1/255 * sum( igno(conjuntoBt(qaux+1),conjuntoOt(qaux+1) )); %entropia con media aritmetica
             
      
    end
    
    [ent,mejorumbral]=min(entropia);
    %con ent no hacemos nada
    
    umbralim.mejorumbral=mejorumbral;
    umbralim.qt=qt;
    umbralim.qt2=qt2;
    umbralim.entropia=entropia;
    
    disp(sum( igno(qt2(1,:),qt(1,:)) ))
    
    
    %imagen(imagen<=optimo)=0;
    %imagen(imagen>optimo)=255;
        
    %imwrite(imagen,'imagen.jpg');
    %imshow(imagen);
    
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

function res=igno(x,y)  %funcion de ignorancia
    
    if min(1-x,1-y)<= 0.5
         res = 2*min(1-x,1-y);
    else
         res = 1/2*min(1-x,1-y);
    end
end


