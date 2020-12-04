/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 16-数值的整数次方.cpp
*   Author      : huihui571
*   Created date: 2020-12-4
*   Description : 实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
 * 快速幂
 * 二分法思路理解：可通过循环x = x^2 的操作，每次把幂从n降至n//2，直至幂降为0。
 * 当n为偶数：x^n = (x^2)*x^n//2
 * 当n为奇数：x^n = x*(x^2)*x^n//2
 */
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;   //0直接返回
        long b = n;            //避免n=-2^31时, -n溢出

        //n < 0情况转换为n >= 0
        if (b < 0) {
            x = 1 / x;
            b = -b;
        }

        double res = 1.0;       //初值为1.0，注意类型为double
        while (b > 0) {
            if ((b & 0x01) == 1)  //相当于b % 2 == 1, b为奇数
                res *= x;       //为奇数时多乘一个x
            x *= x;             //x = x^2
            b >>= 1;            //b = b / 2
        }
        return res;
    }
};
