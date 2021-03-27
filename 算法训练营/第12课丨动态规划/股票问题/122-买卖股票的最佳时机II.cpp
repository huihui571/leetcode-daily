/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 122-买卖股票的最佳时机II.cpp
*   Author      : huihui571
*   Created date: 2020-10-11
*   Description : 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
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

#if 1
/**
 * 动态规划
 * dp数组表示到当前日为止获得的利润
 * 每一天有持有股票/不持有股票两种状态，dp数组第二维分别表示这两种情况
 */
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;   //第一天不买，利润是0
        dp[0][1] = -prices[0];  //第一天买，利润是负

        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]); //不持有股票，则利润等于昨天手里的现金或者昨天持有今天卖掉股票得到的利润
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]); //持有股票，则利润等于昨天持有股票的利润或者昨天不持有今天买了的利润
        }

        return dp[n-1][0];
    }
};
#endif

#if 0
/**
 * 贪心，今天价格大于昨天就可以卖出
 */
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i-1])
            {
                res += prices[i] - prices[i-1];
            }
        }
        return res;
    }
};
#endif