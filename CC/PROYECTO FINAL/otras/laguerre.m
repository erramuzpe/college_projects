function r = laguerre ( poly )
tic

%%  .00049

%POLYROOTS     locate the roots of an arbitrary polynomial using Laguerre's 
%              method
%
%     calling sequences:
%             r = polyroots ( poly, Nmax, TOL )
%             polyroots ( poly, Nmax, TOL )
%
%     inputs:
%             poly    vector containing the coefficients of the polynomial
%                     whose roots are to be computed.  the first entry in
%                     the vector must be the leading coefficient of the
%                     polynomial, and the final entry must be the constant 
%                     term.  zero coefficients must be explicitly provided.
%             Nmax    maximum number of iterations to be performed to 
%                     compute each root
%             TOL     absolute error convergence tolerance
%
%     output:
%             r       vector containing the roots of the polynomial
%
%     NOTE:
%             if POLYROOTS is called with no output arguments, the 
%             roots of the polynomial and the number of iterations
%             required to compute each root are displayed
%
%             if the maximum number of iterations is exceeded, a message
%             to this effect will be displayed and the roots for which
%             convergence had been achieved will be returned
%

Nmax=10000;
TOL= 0.001;

q = poly;
degree = length(poly)-1;
r = zeros ( 1, degree );
its = zeros ( 1, degree );
found = 0;

while ( found < degree - 2 )
    [new, done] = laguerre ( q, 0.0, TOL, Nmax );

    if ( done == 0 )
	   disp('Maximum number of iterations exceeded')
	   return
    end;
	
    if ( abs(imag(new)) == TOL )
  	   found = found + 1;
	   r(found) = real(new);
	   its(found) = done;
	   q = deconv ( q, [ 1 -real(new) ] ); 
    else
	   r(found+1) = new;
	   r(found+2) = conj(new);
	   its(found+1) = done;
	   its(found+2) = done;
	   found = found + 2;
	   q = deconv ( q, conv ( [1 -new], [1 -conj(new)] ) );
    end;
	q = real(q);
end;

if ( found == degree - 2 )
   if ( q(2) == 0 )
      r(degree-1) = sqrt ( -q(3)/q(1) );
      r(degree) = -r(degree-1);
   else
      r(degree-1) = 2*q(3) / ( -q(2) - sign(q(2)) * sqrt ( q(2)*q(2) - 4*q(1)*q(3) ) );
      r(degree) = q(3) / ( r(degree-1) * q(1) );
   end;
else
   r(degree) = -q(2)/q(1);
end;



if ( nargout == 0 )
   disp ( [r' its'] ) 
   toc
end;


function [y, done] = laguerre ( f, x0, TOL, Nmax )

done = 0;
n = length ( f ) - 1;
fp = polyder ( f );
fp2 = polyder ( fp );

for i = 1 : Nmax
    fx = polyval ( f, x0 );
    fpx = polyval ( fp, x0 );
	fp2x = polyval ( fp2, x0 );
	
    if ( abs(fx) < TOL ) 
	   y = x0; done = i;
	   return
    end;
	
	gx = fpx / fx;
	g2 = gx * gx;
	hx = g2 - fp2x / fx;
	
	disc = sqrt ( (n-1) * ( n * hx - g2 ) );
    if ( abs(gx-disc) < abs(gx+disc) )
	   denom = gx+disc;
    else
	   denom = gx-disc;
    end
	dx = n / denom;
        x0 = x0 - dx;

    if ( abs(dx) < TOL ) 
	   y = x0; done = i;
	return
    end	
end
y = x0;

