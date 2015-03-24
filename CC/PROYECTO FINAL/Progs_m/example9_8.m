% Example 9.8 (Householder reduction)
A = [7  2  3 -1;
     2  8  5  1;
     3  5 12  9;
    -1  1  9  7];
A = householder(A);
d = diag(A)'
c = diag(A,1)'
P = householderP(A)