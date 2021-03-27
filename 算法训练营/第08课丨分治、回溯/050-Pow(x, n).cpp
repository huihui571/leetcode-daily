/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 050-Pow(x, n).cpp
*   Author      : huihui571
*   Created date: 2020-07-29
*   Description : 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * 分治法
 * n=n/2，每次使问题规模减小一半，而不是n=n-1。前者是以指数速度减小问题规模，后者是线性。
 */
class Solution
{
public:
    double myPow(double x, int n)
    {
        long long N = n;    //n=-2^31时直接取相反数会溢出，n是32为有符号数[−2^31, 2^31−1]
        if (N < 0)      
        {
           x = 1 / x;
           N = -N;
        }

        return quick_mul(x, N);
    }

    //解决一半问题
    double quick_mul(double x, long long n)
    {
        if (n == 0)
            return 1.0;
        double y = quick_mul(x, n / 2);    //分别解决子问题   
        double result = n % 2 == 0 ? y * y : y * y * x;    //合并子问题，分奇偶

        return result;
    }
};

#if 0
/**
 * 规模大的时候会栈溢出
 */
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1.0;
        double ans;
        if (n > 0)
            ans = x * myPow(x, n - 1);
        if (n < 0)
            ans = (1 / x) * myPow(x, n + 1);

        return ans;
    }
};
#endif