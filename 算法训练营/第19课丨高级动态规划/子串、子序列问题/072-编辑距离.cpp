/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 072-编辑距离.cpp
*   Author      : huihui571
*   Created date: 2020-11-10
*   Description : 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
    插入一个字符
    删除一个字符
    替换一个字符
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
 * 1. Bdirection BFS
 * 2. DP
 *     dp[i][j]表示word1[0:i]与word2[0:j]的编辑距离，则
 *     if char[i] == char[j]:
 *         //当前这两个字母相等，则这次不需要编辑
 *         dp[i][j] = dp[i - 1][j - 1]  
 *     else
 *         //若不相等，把word1往word2去变换(反之一样)
 *         1. 在位置word1[i]插入一个和word2[j]一样的字符，word2[j]就被匹配了，前移j，继续跟i对比. dp[i][j - 1] + 1
 *         2. 把word1[i]这个字符删掉，前移i，继续跟j对比. dp[i - 1][j] + 1
 *         3. 把word1[i]替换为word2[j]，这样他俩就匹配了，同时前移i，j继续对比. dp[i - 1][j - 1] + 1
 *         dp[i][j] = MIN(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1
 *  3. 参考062不同路径，这是一个表格规划问题，当前值可以由左、左上、上方表格递推而来。
 * 
 */
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        //初始化表格两个边
        for (int i = 0; i < m + 1; ++i)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j < n + 1; ++j)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i < m + 1; ++i)
        {
            for (int j = 1; j < n + 1; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            }
        }

        return dp[m][n];
    }
};