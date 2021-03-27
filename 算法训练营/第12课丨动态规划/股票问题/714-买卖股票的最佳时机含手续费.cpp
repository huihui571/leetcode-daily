/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 714-买卖股票的最佳时机含手续费.cpp
*   Author      : huihui571
*   Created date: 2020-10-17
*   Description : 给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。
你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
返回获得利润的最大值。
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
 * 只要每次卖出减去手续费就行了
 */
class Solution
{
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        if (prices.empty())
            return 0;
        int n = prices.size();
        int dp_0 = 0;
        int dp_1 = -prices[0];

        for (int i = 1; i < n; ++i)
        {
            dp_0 = max(dp_0, dp_1 + prices[i] - fee);
            dp_1 = max(dp_1, dp_0 - prices[i]); 
        }

        return dp_0;
    }
};