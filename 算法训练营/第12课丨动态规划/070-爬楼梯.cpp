/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 070-爬楼梯.cpp
*   Author      : huihui571
*   Created date: 2020-09-25
*   Description : 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。
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
 * 动态规划法
 * 当前问题的解，等于从下一级台阶走上来的方法数+从下两级台阶走上来的方法数
 * dp[i] = dp[i - 1] + dp[i - 2];
 */
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 2)          //别忘了大于2才开始递推
            return 1;

        int *dp = new int[n + 1]();
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < n + 1; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};