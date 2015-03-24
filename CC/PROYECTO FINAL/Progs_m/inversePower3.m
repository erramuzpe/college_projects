function eVal = inversePower3(d,c,b)
% Finds smallest eigenvalue of [A]{x} = eVal[B]{x}
% by the invers power method.
% USAGE: eVal = inversePower3(d,c,b)
% [A] must be tridiagonal: [A] = [c\d\c];
% [B] must be diagonal: [B] =[\b\].

n = length(d); e = c;
z = zeros(n,1); 
v = rand(n,1); v = v/sqrt(dot(v,v));
[c,d,e] = LUdec3(c,d,e);
for i = 1:50
    z = b.*v;            % {z} = [B]{v}
    z = LUsol3(c,d,e,z);
    zMag = sqrt(dot(z,z)); z = z/zMag;
    if sqrt(dot(v - z,v - z)) < 1.0e-6
        if dot(v,z) > 0; eVal = 1/zMag;
        else; eVal = -1/zMag; end
        return
    else; v = z; end
end
error('Too many iterations')
        
            
    
    
    
