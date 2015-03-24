function x = buildvec
for i = 1:1000
    elem = input('==> ');
    if isempty(elem)
        break
    end
    x(i) = elem;
end    