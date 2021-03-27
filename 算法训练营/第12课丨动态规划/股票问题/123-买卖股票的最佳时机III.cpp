/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 123-买卖股票的最佳时机III.cpp
*   Author      : huihui571
*   Created date: 2020-10-11
*   Description : 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
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
 * dp数组有三维，第一维是天数，第二维是当前剩余最大交易次数，第三维是持有1或不持有0股票两种状态
 * dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k][0] - prices[i]) 今天持有=max(昨天持有今天保持，昨天不持有今天买入)
 * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k-1][1] + prices[i]) 今天不持有=max(昨天不持有今天保持，昨天持有今天卖出)
 * k在买入或卖出的时候-1都可以
 */
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {

        int n = prices.size();
        int k_max = 2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k_max + 1, vector<int>(2)));

        //初始化所有i=0的情况。(要遍历另外两个维度)
        // dp[0][2][1] = -prices[0];
        // dp[0][2][0] = 0;
        // dp[0][1][1] = -prices[0];
        // dp[0][1][0] = 0;
        // dp[0][0][1] = -prices[0];
        // dp[0][0][0] = 0;
        for (int k = 0; k < k_max + 1; ++k)
        {
            dp[0][k][0] = 0;
            dp[0][k][1] = -prices[0];   //买入则现金减少prices[0]
        }

        //初始化所有k=0的情况，即不允许交易。(要遍历另外两个维度)
        for (int i = 0; i < n; ++i)
        {
            dp[i][0][0] = 0;
            dp[i][0][1] = INT32_MIN;    //负无穷表示这种不可能的情况
        }

        for (int i = 1; i < n; ++i)
        {
            dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][2][1] + prices[i]);
            dp[i][2][1] = max(dp[i-1][2][1], dp[i-1][1][0] - prices[i]);
            dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i]); 
            dp[i][1][1] = max(dp[i-1][1][1],  - prices[i]);
        }

        return dp[n-1][2][0];   //最后一天，最多还能交易k_max次，不持有股票的状态
    }
};
#endif

#if 1
/**
 *空间优化，每次只用到了前一次的状态
 */
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int dp_i20 = 0; //第一天，还剩两次机会，不持有股票
        int dp_i10 = 0; //第一天，还剩一次机会，不持有股票
        int dp_i21 = -prices[0]; //第一天，还剩两次机会，持有股票
        int dp_i11 = -prices[0]; //第一天，还剩一次机会，持有股票

        for (int p : prices)
        {
            dp_i20 = max(dp_i20, dp_i21 + p);   //在昨天基础上不动，或者卖出了
            dp_i21 = max(dp_i21, dp_i10 - p);   //在昨天基础上不动，或者买入了。每次买入，k-1
            dp_i10 = max(dp_i10, dp_i11 + p);   //在昨天基础上不动，或者卖出了
            dp_i11 = max(dp_i11, - p);   //dp_i00 - p 在昨天基础上不动，或者买入了。每次买入，k-1
        }
        
        return dp_i20;
    }
};
#endif

