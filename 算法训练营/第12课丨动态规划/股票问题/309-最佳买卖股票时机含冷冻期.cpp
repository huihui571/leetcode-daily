/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 309-最佳买卖股票时机含冷冻期.cpp
*   Author      : huihui571
*   Created date: 2020-10-17
*   Description : 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
    你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
    卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
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

#if 0
/**
 * 有持有1、不持有0、冷冻期2三种状态。
 * 
 */
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty())
            return 0;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;

        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]); //不动，或者卖出
            dp[i][1] = max(dp[i-1][1], dp[i-1][2] - prices[i]); //不动，或者从冷静期转为持有
            dp[i][2] = dp[i-1][0];  //冷静期复制前一天卖出后的状态
        }

        return dp[n-1][0];
    }
};
#endif

#if 1
/**
 * 空间优化
 * 
 */
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty())
            return 0;
        int n = prices.size();
        int dp_0 = 0;
        int dp_1 = -prices[0];
        int dp_2 = 0;

        for (int i = 1; i < n; ++i)
        {
            int tmp = dp_0;    //在dp_0被覆盖前先保存
            dp_0 = max(dp_0, dp_1 + prices[i]); //不动，或者卖出
            dp_1 = max(dp_1, dp_2 - prices[i]); //不动，或者从冷静期转为持有
            dp_2 = tmp;  //冷静期复制前一天卖出后的状态
        }

        return dp_0;
    }
};
#endif