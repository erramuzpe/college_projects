% Example 2.8 (Choleski decomposition)
A = [1.44 -0.36  5.52  0.00;
    -0.36 10.33 -7.78  0.00;
     5.52 -7.78 28.40  9.00;
     0.00  0.00  9.00 61.00];
 L = choleski(A)
 Check = L*L'  % Verify the result