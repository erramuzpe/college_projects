% Pruebas para vect prop.
contador=0;


for numvect=1:20
    for carpeta=0:4
        switch carpeta
        case 0
           numim = 20;
        case 1
           numim = 16;      
        case 2
           numim = 12;
        case 3
            numim = 8; 
        otherwise %case4
           numim = 4;
        end  
        
        
        for imagen=100:100:400
        
            if numvect<=numim
                bien = prac4(carpeta,strcat(num2str(imagen)),numvect);
                if bien==1
                    contador=contador + 1;
                end
                
            end
        end
        
        if numvect<=numim
        fprintf('NUMimagenesxcara %d, NUMVECTS  %d : aciertos-> %d\n', numim/4, numvect,(contador/4*100));
        end
        contador=0;
    end
end