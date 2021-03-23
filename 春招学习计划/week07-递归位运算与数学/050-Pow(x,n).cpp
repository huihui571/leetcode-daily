/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 050-Pow(x,n).cpp 
*   Author      : huihui571
*   Created date: 2021-03-06
*   Description : 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。
*   -100.0 < x < 100.0
*   -231 <= n <= 231-1
*   -104 <= xn <= 104  
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 快速幂
 */
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;  //防止n取反时溢出
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return quick_mul(x, N);
    }

    double quick_mul(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }

        double y = quick_mul(x, n / 2);

        if (n % 2 == 0) {
            return y * y; 
        }
        else {
            return x * y * y;
        }
    }
};
