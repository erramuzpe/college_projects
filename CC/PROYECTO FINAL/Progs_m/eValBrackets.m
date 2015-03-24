function r = eValBrackets(c,d,m)
% Brackets each of the m lowest eigenvalues of A = [c\d\c]
% so that there is one eivenvalue in [r(i), r(i+1)].
% USAGE: r = eValBrackets(c,d,m).

[eValMin,eValMax]= gerschgorin(c,d);  % Find global limits
r = ones(m+1,1); r(1) = eValMin;
% Search for eigenvalues in descending order
for k = m:-1:1
    % First bisection of interval (eValMin,eValMax)
    eVal = (eValMax + eValMin)/2;
    h = (eValMax - eValMin)/2;
    for i = 1:100
        % Find number of eigenvalues less than eVal
        num_eVals = count_eVals(c,d,eVal);
        % Bisect again & find the half containing eVal
        h = h/2;
        if num_eVals < k ; eVal = eVal + h;
        elseif num_eVals > k ; eVal = eVal - h;
        else; break
        end
    end
    % If eigenvalue located, change upper limit of 
    % search and record result in {r}
    ValMax = eVal; r(k+1) = eVal;
end    