/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 032-最长有效括号.cpp
*   Author      : huihui571
*   Created date: 2020-11-14
*   Description : 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
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

#if 0
/**
 * dp[i]表示子串s[0:i]中，最长有效子串的长度。
 */
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.length();
        if (n == 0)
            return 0;
        vector<int> dp(n);

        for (int i = 1; i < n; ++i)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;      //i之前匹配数+2
                }
                else
                {
                    //如果前面是')',向前寻找能与当前')'匹配的未匹配'('
                    int pos = i - dp[i - 1] - 1;    //跨过中间已经互相匹配的最长有效括号对
                    if (pos >= 0 && s[pos] == '(')
                    {
                        dp[i] = (pos >= 1 ? dp[pos - 1] : 0) + dp[i - 1] + 2;  //pos之前匹配数+i之前匹配数+2
                    }   
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
#endif

#if 1
/**
 * 可以考虑将问题分为两部分：
 * 1. 通过某种规则将所有能被正确匹配的括号替换成1，不能的替换成0。
 * 2. 求诸如11111011这样的序列中最长连续1的长度。
 * 这样分为括号匹配和动态规划求最长两个问题。
 */
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.length();
        if (n == 0)
            return 0;
        vector<int> dp(n);

        for (int i = 1; i < n; ++i)
        {

        }

        return *max_element(dp.begin(), dp.end());
    }
};
#endif