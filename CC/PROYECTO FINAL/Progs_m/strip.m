function s2 = strip(s1)
s2 = '';
for i = 1:length(s1)
    if s1(i) == ' '
        continue
    elseif s1(i) == '.'
        return
    else
        s2 = strcat(s2,s1(i));
    end
end    
    
