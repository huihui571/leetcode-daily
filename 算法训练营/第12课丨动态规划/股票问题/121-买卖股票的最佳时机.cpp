/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 121-买卖股票的最佳时机.cpp
*   Author      : huihui571
*   Created date: 2020-10-11
*   Description : 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
注意：你不能在买入股票前卖出股票。
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
 * 1.动态规划
 * 因此，我们只需要遍历价格数组一遍，记录历史最低点，
 * 然后在每一天考虑这么一个问题：如果我是在历史最低点买进的，那么我今天卖出能赚多少钱？
 * 当考虑完所有天数之时，我们就得到了最好的答案。
 */
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<int> dp(n);      //dp数组记录到当前为止能获得的最大利润。
        dp[0] = -prices[0];      //开始利润为负无穷
        int lowest_price = prices[0];   //记录当日之前的最低价格

        for (int i = 1; i < n; ++i)
        {
            int cur_interest = prices[i] - lowest_price;    //当日利润
            dp[i] = max(dp[i-1], cur_interest);             //当日卖或者昨天卖两种选择
            if (prices[i] < lowest_price)                   //更新最低价格
                lowest_price = prices[i];
        }

        return dp[n-1] < 0 ? 0 : dp[n-1];    
    }
};
#endif

#if 1
/**
 * 2.单调栈
 * 单调上升序列的最大值减最小值就是卖出时机
 */
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int res = 0;
        vector<int> St;             //因为要取栈底元素，所以用vector代替
        prices.emplace_back(-1);    //末尾添加一个最小值

        for (int i = 0; i < prices.size(); ++i)
        {
            while (!St.empty() && prices[i] < St.back())    //遇到小于栈顶的开始弹出
            {
                res = max(res, St.back() - St.front());     //计算最大利润
                St.pop_back();
            }
            St.push_back(prices[i]);    //大于栈顶的直接入栈
        }

        return res;
    }
};
#endif
