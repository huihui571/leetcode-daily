/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 19-正则表达式匹配.cpp
*   Author      : huihui571
*   Created date: 2020-12-07
*   Description : 请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
*   在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。
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
 * dp[i][j]表示主串前i个字符和模式串前j个字符能否匹配
 * 如果p[j]是正常字符或者‘.’，则dp[i][j] = d[i - 1][j - 1]
 * 如果p[j]是‘*’，代表前一个字符c可以重复0次或多次，它们是一个整体c*，分两种情况：
 *   1.s[i]和c*不匹配，那跳过c*这两个字符 dp[i][j] = dp[i][j - 2]
 *   2.s[i]和c*匹配，
 * 初值：dp[0][0] = true 两个空的能匹配, dp[1][0].。dp[n][0] = false非空串和空正则比不匹配
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        //lambda表达式定义函数对象(相当于匿名函数)
        auto matches = [&](int i, int j) {
            if (i == 0)
                return false;
            if (p[j - 1] == '.')
                return true;
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] != '*') {
                    if (matches(i, j)) {
                        dp[i][j] |= dp[i - 1][j - 1];
                    }
                }
                else {
                    dp [i][j] |= dp[i][j - 2];
                    if (matches(i, j - 1)) {
                        dp[i][j] |= dp[i - 1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};
