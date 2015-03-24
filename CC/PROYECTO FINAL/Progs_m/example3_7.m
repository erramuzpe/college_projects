% Example 3.7 (Cubic spline)
xData = [1; 2; 3; 4; 5];
yData = [0; 1; 0; 1; 0];
k = splineCurv(xData,yData);
while 1
    x = input('x = ');
    if isempty(x)
        fprintf('Done'); break
    end    
    y = splineEval(xData,yData,k,x)
    fprintf('\n')
end


    