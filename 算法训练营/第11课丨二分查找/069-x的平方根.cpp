/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 069-x的平方根.cpp
*   Author      : huihui571
*   Created date: 2020-09-14
*   Description : 实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
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
#include <cmath>

using namespace std;

#if 0
/**
 * 二分法
 * x的平方根范围在1～x之间，在这之间采用二分搜索法，每次取整数。
 * 注意乘平方后int溢出问题
 */
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
            return x;
        int left = 1;
        int right = x;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            long long square = mid * mid;
            if (square == x)
            {
                return mid;
            }
            else if (square > x)
            {
                right = mid - 1;
            }
            else if (square< x)
            {
                left = mid + 1;
            }
        }   
        //此时left==right
        return (long long)left * left > x ? left - 1 : left;      
    }
};
#endif


#if 1
/**
 * 牛顿迭代法
 * x0=C作为初始值，迭代方程xi+1 = (xi + C/xi) / 2
 */
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return x;

        double C = x, xi = C;
        while (true)
        {
            double xii = (xi + C / xi) / 2;
            if (fabs(xii - xi) < 1e-7)
            {
                break;
            }
            xi = xii;
        }

        return (int)xi;
    }
};
#endif