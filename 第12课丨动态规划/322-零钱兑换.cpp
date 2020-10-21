/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 322-零钱兑换.cpp
*   Author      : huihui571
*   Created date: 2020-09-09
*   Description : 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
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
 * 动态规划。dp[i]表示总金额为i时问题的解
 * dp[i] = min(dp[i], dp[i-k] + 1) for k in coins
 */
class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int MAX = amount + 1;
        vector<int> dp(amount+1, MAX);
        dp[0] = 0;

        for (int i = 1; i < amount + 1; ++i)
        {
            for (auto c : coins)    //各种面额
            {
                if(c > i)
                    continue;                       //面额大于目标总金额
                dp[i] = min(dp[i], dp[i-c] + 1);    //最少硬币个数，对于每一个面额c有用或不用两种情况
            }
        }
        
        return dp[amount] == MAX ? -1 : dp[amount];
    }
};

#if 0
/**
 * 贪心法。每次先用最大面额去试。
 * 这个题实际上是贪心不能得到最优解的反例哈哈,1,2,5 10的例子能行是因为硬币面额是倍数关系，可以证明贪心能用。
 */
class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        sort(coins.rbegin(), coins.rend());     //面额由大到小排列

        int i = 0;
        int cnt = 0;
        while(amount)
        {
            cnt += amount / coins[i];       //这个面额用几枚
            amount = amount % coins[i];     //余数
            i++;
            if (i == coins.size())      //所有面额硬币用完还没凑出来
                return -1;
        }

        return cnt;
    }
};
#endif