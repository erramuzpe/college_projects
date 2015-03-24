%Asier Erramuzpe Prac3
%Grupo A:Ejercicio 7
%Construir una funcin que calcule, dadas dos matrices cuadradas P y Q, una nueva matriz R donde
%cada elemento viene calculado como
%R(x,z)=max(min(P(x,y),Q(y,z)))
%p= [1 3 5;2 8 6; 4 1 0]
%q= [2 2 5;2 3 4; 6 1 7]

function m = ejercicio7(m1,m2)
    z = length(m1);
    m = zeros(z,z);
    maximo=-10000;
    for i=1:z
        for j=1:z
            for h=1:z
                maximo = max(maximo,(min(m1(i,h),m2(h,j))));
            end
            m(i,j)=maximo;
            maximo=-10000;
        end
    end
end