/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 070-爬楼梯.cpp
*   Author      : huihui571
*   Created date: 2020-07-03
*   Description : 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
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
 * 斐波那契数列。f(n) = f(n-1) + f(n-2)
 * a[i] = a[i-1] + a[i-2] or last_last, last, current or dp[0], dp[1], cur
 * 思路：1.懵逼时先想最简单情况，然后找规律，数学归纳法
 *      2.找最近重复子问题
 */
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }
        int last_last = 1;
        int last = 2;
        int cur;
        for (int i = 2; i < n; ++i)
        {
            cur = last_last + last;
            last_last = last;       //注意先保存上上次，再保存上次。以免上次值被覆盖。
            last = cur;       
        }

        return cur;
    }
};