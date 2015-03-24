function v = swapCols(v,i,j)
% Swap columns i and j of vector or matrix v.

temp = v(:,i);
v(:,i) = v(:,j);
v(:,j) = temp;