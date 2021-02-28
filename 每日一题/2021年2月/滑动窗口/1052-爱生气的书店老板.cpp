/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 1052-爱生气的书店老板.cpp 
*   Author      : huihui571
*   Created date: 2021-02-23
*   Description : 今天，书店老板有一家店打算试营业 customers.length 分钟。每分钟都有一些顾客（customers[i]）会进入书店，所有这些顾客都会在那一分钟结束后离开。
*   在某些时候，书店老板会生气。 如果书店老板在第 i 分钟生气，那么 grumpy[i] = 1，否则 grumpy[i] = 0。 当书店老板生气时，那一分钟的顾客就会不满意，不生气则他们是满意的。
*   书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续 X 分钟不生气，但却只能使用一次。
*   请你返回这一天营业下来，最多有多少客户能够感到满意的数量。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
* 先算不控制情绪的收益，然后在看每个长度为X的窗口能增加的最大额外收益
*/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int profit = 0;
        for (int i = 0; i < customers.size(); i++) {
            profit += grumpy[i] == 0 ? customers[i] : 0; 
        }

        int extProfit = 0;
        int maxExtProfit = INT32_MIN;
        int left = 0, right = 0;
 
        while (right < customers.size()) {
            extProfit += grumpy[right] == 1 ? customers[right] : 0;
            if (right - left >= X) {
                extProfit -= grumpy[left] == 1 ? customers[left] : 0;
                left++;
            }
            maxExtProfit = max(maxExtProfit, extProfit);
            right++;
        }
        
        return profit + maxExtProfit;
    }
};

