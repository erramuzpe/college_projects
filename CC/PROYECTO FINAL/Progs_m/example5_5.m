% Example 5.5 (Polynomial fit)
xData = [0.0; 0.2; 0.4; 0.6; 0.8; 1.0; 1.2; 1.4];
yData = [1.9934; 2.1465; 2.2129; 2.1790;...
                2.0683; 1.9448; 1.7655; 1.5891];
format short e
while 1
    k = input('degree of polynomial = ');
    if isempty(k)        % Loop is terminated   
        fprintf('Done')  % by pressing "return"
        break
    end
    coeff = polyFit(xData,yData,k+1)
    sigma = stdDev(coeff,xData,yData)
    fprintf('\n')
end    
     