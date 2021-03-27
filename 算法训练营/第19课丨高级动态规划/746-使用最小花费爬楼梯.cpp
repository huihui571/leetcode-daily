/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 746-使用最小花费爬楼梯.cpp
*   Author      : huihui571
*   Created date: 2020-11-10
*   Description : 数组的每个索引作为一个阶梯，第 i个阶梯对应着一个非负数的体力花费值 cost[i](索引从0开始)。
每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯。
您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯。
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
#include <unordered_set>
#include <algorithm>

using namespace std;
/**
 * Once you pay the cost, you can either climb one or two steps. 
 * 英文说得很清楚了，支付这一级阶梯上写的代价，然后可以选择走一步或走两步。
 * 中文翻译傻B，题目都说不明白！
 */

/**
 * 可以理解为到每一级台阶都要接受一定额的惩罚，起点无论是从0还是从1开始都必须接受惩罚，终点不需要惩罚。
 */
class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        cost.push_back(0);      //终点台阶的惩罚是0

        vector<int> dp(cost.size() + 1);
        
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i <= cost.size(); ++i)
        {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }

        return dp[cost.size() - 1];
    }
};