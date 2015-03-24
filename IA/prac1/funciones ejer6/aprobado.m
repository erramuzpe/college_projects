function ap = aprobado(x)
    if (x<=4 && x>7)
        ap=0;
    elseif x>=5 && x>6
        ap=1;
    elseif x>4 && x<=5
        ap = x-4;
    else
        ap = 7-x;
    end
end
    