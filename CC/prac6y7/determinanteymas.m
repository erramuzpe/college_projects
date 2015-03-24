MAS /usr/local/matlabR2010a/toolbox/comm/comm/@gf/



function ans = det(A)
%DET  Determinant of square GF matrix.
%   DET(X) is the determinant of the square matrix X.

%    Copyright 1996-2007 The MathWorks, Inc.
%    $Revision: 1.2.4.2 $  $Date: 2007/09/14 15:58:44 $ 

global GF_TABLE_M GF_TABLE_PRIM_POLY GF_TABLE1 GF_TABLE2

if ~isequal(A.m,GF_TABLE_M) | ~isequal(A.prim_poly,GF_TABLE_PRIM_POLY)
   [GF_TABLE_M,GF_TABLE_PRIM_POLY,GF_TABLE1,GF_TABLE2] = gettables(A);
end

ans = gf(uint32_det(A.x,A.m,A.prim_poly),A.m,A.prim_poly);


function ans = uint32_det(x,M,prim_poly)
global GF_TABLE1 GF_TABLE2

[m,n] = size(x);
if (m~=n)
   error('comm:gf_det:NotASquare','must be square')
end
if m==1
  ans = x;
  return
end
d = uint32(0);
for i=1:m
  subdet = uint32_det(x(2:m,[1:i-1 i+1:m]),M,prim_poly); % sub determinant
  %A.x(1,i), subdet
  temp = gf_mex(x(1,i),subdet,M,'times',prim_poly,GF_TABLE1,GF_TABLE2);  % multiply
  d = gf_mex(d,temp,M,'plus',prim_poly); % add
end

ans = d;
