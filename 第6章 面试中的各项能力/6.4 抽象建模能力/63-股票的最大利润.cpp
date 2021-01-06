/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 63-股票的最大利润.cpp
*   Author      : huihui571
*   Created date: 2021-01-06
*   Description : 假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
*   输入: [7,1,5,3,6,4] 输出: 5
*   解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
*   注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
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
 * 在最低价买入，最高价卖出就行了
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = INT32_MAX, profit = 0;
        for (int price : prices) {
            cost = min(cost, price);
            profit = max(profit, price - cost);
        }

        return profit;
    }
};