function I = triangleQuad(func,x,y)
% Cubic quadrature over a triangle.
% USAGE: I = triangleQuad(func,x,y)
% INPUT:
% func = handle of function to be integrated.
% x    = [x1;x2;x3] x-coordinates of corners.
% y    = [y1;y2;y3] y-coordinates of corners.
% OUTPUT:
% I    = integral

alpha = [1/3 1/3 1/3; 1/5 1/5 3/5;...
         3/5 1/5 1/5; 1/5 3/5 1/5];
W = [-27/48; 25/48; 25/48; 25/48];
xNode = alpha*x; yNode = alpha*y;
A = (x(2)*y(3) - x(3)*y(2)...
   - x(1)*y(3) + x(3)*y(1)...
   + x(1)*y(2) - x(2)*y(1))/2;
sum = 0;
for i = 1:4
    z = feval(func,xNode(i),yNode(i));
    sum = sum + W(i)*z;
end
I = A*sum;
