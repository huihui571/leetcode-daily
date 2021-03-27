/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 60-n个骰子的点数.cpp
*   Author      : huihui571
*   Created date: 2021-01-05
*   Description : 把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
* 你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。
* 输入: 1 输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
* 输入: 2 输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
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
#include <math.h>

using namespace std;

/**
 * 状态转移参考青蛙跳台阶问题
 * n个骰子，一共有6^n种结果，其中每一种结果（即点数之和s）的范围是n~6n，共6n-(n-1)=5n+1个值。每一个s的概率为s出现次数/6^n。
 * dp[i][j]表示投掷i个骰子，点数之和为j的事件出现次数。
 * dp[i][j] += d[i-k][j-k] k=1...6，考虑第n个骰子的点数为k，那么和为j的状态就需要从dp[i-1][j-k]转移而来。要保证j-k>0，因为骰子没有负数。
 * 只有一共骰子时，s的范围是1~6，每种可能出现的次数都为1。
 */
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> res(5 * n + 1);
        vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1, 0));

        //初始化
        for (int i = 1; i <= 6; ++i) {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= n ; ++i) {
            for (int j = i; j <= 6 * n; ++j) {   //点数s >= n，所以j从i开始
                //进行状态转移
                for (int k = 1; k <= 6; ++k) {
                    if (j - k > 0)
                        dp[i][j] += dp[i - 1][j - k];
                    else
                        break;          //如果j-k<0，那么后面的k肯定也小于
                }
            }
        }

        double all = pow(6.0, n);
        for (int i = 0; i < 5 * n + 1; ++i) {
            res[i] = dp[n][i + n] / all;        //和s范围是n~6n
        }

        return res;
    }
};
