/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 122-买卖股票的最佳时机II.cpp
*   Author      : huihui571
*   Created date: 2020-09-12
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

/**
 * 贪心法，每次在波谷买入，波峰卖出。
 */
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int res = 0;
        int price_in = 0;
        int price_out = 0;
        bool buy_flag = false;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (buy_flag == false && prices[i] > prices[i-1])
            {
                price_in = prices[i-1];
                buy_flag = true;
            }
            if (buy_flag == true && prices[i] < prices[i-1])
            {
                price_out = prices[i-1];
                res += price_out - price_in;
                buy_flag = false;
            }
        }
        //末尾特殊处理
        if (buy_flag == true)
        {   
            price_out = prices[prices.size() - 1];
            res += price_out - price_in;
        }

        return res;      
    }
};