function n = notable(x)
    if (x<=7 && x>9)
        n=0;
    elseif x>=7 && x>8
        n=1;
    elseif x>6 && x<=7
        n = x-4;
    else
        n = 9-x;
    end
end
    