/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 1143-最长公共子序列.cpp
*   Author      : huihui571
*   Created date: 2020-11-21
*   Description : 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。
一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。
若这两个字符串没有公共子序列，则返回 0。
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
 * 注意：子序列不一定连续，子串要连续
 * 经典二维动态规划问题，定义dp[i][j]为text1前i个字符与text2前j个字符的最长公共子序列
 * 则dp[0][j]=dp[i][0]=0
 * if text1[i - 1] == text[j - 1]:
 *     dp[i][j] = dp[i - 1][j - 1] + 1;
 * else
 *     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
 */
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.length();
        int n = text2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m][n];
    }
};