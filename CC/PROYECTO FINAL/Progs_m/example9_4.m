% Example 9.4 (Power method)
S = [-30 10 20; 10 40 -50; 20 -50 -10];
v = [1; 0; 0];
for i = 1:100
    vOld = v; z = S*v; zMag = sqrt(dot(z,z));
    v = z/zMag; vSign = sign(dot(vOld,v));
    v = v*vSign;
    if sqrt(dot(vOld - v,vOld - v)) < 1.0e-6
        eVal = vSign*zMag
        numIter = i
        return
    end
end
error('Too many iterations')