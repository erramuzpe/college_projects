function eVals = eigenvals3(C,D,m)
% Computes the smallest m eigenvalues of A = [C\D\C].
% USAGE: eVals = eigenvals3(C,D,m).
% C and D must be delared 'global' in calling program.

eVals = zeros(m,1);
r = eValBrackets(C,D,m); % Bracket eigenvalues
for i=1:m
    % Solve |A - eVal*I| for eVal by Brent's method
    eVals(i) = brent(@func,r(i),r(i+1));
end

function f = func(eVal);
% Returns |A - eVal*I| (last element of Sturm seq.)
global C D
p = sturmSeq(C,D,eVal);
f = p(length(p));
    