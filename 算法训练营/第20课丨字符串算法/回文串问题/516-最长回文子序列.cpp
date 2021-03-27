/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 516-最长回文子序列.cpp
*   Author      : huihui571
*   Created date: 2020-11-22
*   Description : 给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。
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
 * dp[i][j]表示s[i:j]中的最长回文子序列
 * i==j时dp[i][j]=1,i>j时dp[i][j]=0
 */
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = 1;
        }

        //由于i是从i+1过来，所以i要倒着遍历，可以画图理解一下
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][n - 1];
    }
};