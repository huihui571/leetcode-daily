/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 46-把数字翻译成字符串.cpp
*   Author      : huihui571
*   Created date: 2020-12-29
*   Description : 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
*   一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
 * 动态规划
 */
class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        int n = str.length();
        if (n == 0)
            return 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        if (n == 1)
            return 1;
        if (str[0] > '2' || str[0] == '2' && str[1] > '5')
            dp[1] = 1;
        else
            dp[1] = 2;

        for (int i = 2; i < n; ++i) {
            if (str[i - 1] > '2' || str[i -1] == '2' && str[i] > '5' || str[i - 1] == '0')       //只能单独译
                dp[i] = dp[i - 1];
            else
                dp[i] = dp[i - 2] + dp[i - 1];      //可以和上一位结合译，单独dp[i-1] + 结合dp[i-2]
        }

        return dp[n - 1];
    }
};

