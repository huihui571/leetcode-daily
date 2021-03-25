/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 编辑距离II.cpp
*   Author      : huihui571
*   Created date: 2021-03-23
*   Description : 给你两个单词s 和t，请你计算出将s转换成t 所使用的最少操作数。
*   你可以对一个单词进行如下两种操作：
*       删除一个字符
*       替换一个字符
*   注意：
*      不允许插入操作
*      题目保证有解
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 题目要求只能对s进行操作，即从s转换成t，所以要保存i >= j，即只填充下三角区域
 * dp[i][j]表示将s前i个字符转成t前j个字符所用的最少操作次数。
 * NOTE: 删除是有限制的：s要至少比t多一个字符即i >= j+1才能删除，否则删完s就比t短了。
 */
class Solution {
public:
    int edit_distance(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];    //不修改
                }
                else {
                    if (i >= j + 1) {
                        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + 1; //j > i + 1 才能删除或者替换
                    }
                    else {
                        dp[i][j] = dp[i - 1][j - 1] + 1;    //否则只能替换
                    }
                }
            }
        }

        return dp[m][n];
    }
};

