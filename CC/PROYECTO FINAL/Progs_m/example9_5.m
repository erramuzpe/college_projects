% Example 9.5 (Inverse power method)
s = 5;
A = [11  2  3  1  4;
      2  9  3  5  2;
      3  3 15  4  3;
      1  5  4 12  4;
      4  2  3  4 17];
[eVal,eVec] = invPower(A,s)
    