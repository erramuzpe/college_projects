function [eVals,eVecs] = sortEigen(eVals,eVecs)
% Sorts eigenvalues & eigenvectors into ascending 
% order of eigenvalues.
% USAGE: [eVals,eVecs] = sortEigen(eVals,eVecs)

n = length(eVals);
for i = 1:n-1
    index = i; val = eVals(i);
    for j = i+1:n
        if eVals(j) < val
            index = j; val = eVals(j);
        end
    end    
    if index ~= i
        eVals = swapRows(eVals,i,index);
        eVecs = swapCols(eVecs,i,index);
    end
end    