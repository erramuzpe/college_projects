function [eValMin,eValMax]= gerschgorin(c,d)
% Evaluates the global bounds on eigenvalues 
% of A = [c\d\c].
% USAGE: [eValMin,eValMax]= gerschgorin(c,d).

n = length(d);
eValMin = d(1) - abs(c(1));
eValMax = d(1) + abs(c(1));
for i = 2:n-1
    eVal = d(i) - abs(c(i)) - abs(c(i-1));
    if eVal < eValMin; eValMin = eVal; end
    eVal = d(i) + abs(c(i)) + abs(c(i-1));
    if eVal > eValMax; eValMax = eVal; end
end
eVal = d(n) - abs(c(n-1));
if eVal < eValMin; eValMin = eVal; end
eVal = d(n) + abs(c(n-1));
if eVal > eValMax; eValMax = eVal; end

    