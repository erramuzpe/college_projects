function num_eVals = count_eVals(c,d,lambda)
% Counts eigenvalues smaller than lambda of matrix
% A = [c\d\c]. Uses the Sturm sequence.
% USAGE: num_eVals = count_eVals(c,d,lambda).

p = sturmSeq(c,d,lambda);
n = length(p);
oldSign = 1; num_eVals = 0;
for i = 2:n
    pSign = sign(p(i));
    if pSign == 0; pSign = -oldSign; end
    if pSign*oldSign < 0
        num_eVals = num_eVals + 1;
    end
    oldSign = pSign;
end