/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 115-不同的子序列.cpp
*   Author      : huihui571
*   Created date: 2020-11-16
*   Description : 给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
题目数据保证答案符合 32 位带符号整数范围。
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
 * dp[i][j]代表字符串S的前i个字符所构成的子序列中包含字符串T的前j个字符的情况个数
 * 然后开始填二维表格，
 * 如果s[i] == t[j],则：s[0:i-1]与t[0:j-1]子串数量 + s[0:i-1]与t[0:j]子串数量
 * 如果s[i] != t[j],则：和s[0:i-1]与t[0:j]子串数量一样
 */
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.length(), n = t.length();
        if (m == 0 || n == 0)
            return 0;

        vector<vector<long>> dp(m + 1, vector<long>(n + 1));

        for (int i = 0; i <= m; ++i)
        {
            dp[i][0] = 1;   //初始化第一列
        }

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s[i - 1] != t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                cout << dp[i][j] << endl;
            }
        }

        return dp[m][n];
    }
};