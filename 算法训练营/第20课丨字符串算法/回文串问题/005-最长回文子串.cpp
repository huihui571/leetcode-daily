/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 005-最长回文子串.cpp
*   Author      : huihui571
*   Created date: 2020-11-22
*   Description : 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
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
 * 中心扩散法，从每一个位置出发，向两边扩散，遇到不相等时结束，同时记录回文子串的长度。
 */
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int left = 0, right = 0;
        int len = 1, max_len = 0;
        int max_start = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            left = i - 1;
            right = i + 1;

            while (left >= 0 && s[left] == s[i])
            {
                len++;
                left--;
            }

            while (right < s.length() && s[right] == s[i])
            {
                len++;
                right++;
            }

            while (left >= 0 && right < s.length() && s[left] == s[right])
            {
                len += 2;
                left--;
                right++;
            }

            if (len > max_len)
            {
                max_len = len;
                max_start = left;
            }

            len = 1;
        }
        
        return s.substr(max_start + 1, max_len);
    }
};
#endif

#if 1
/**
 * 动态规划，dp[i][j]表示s[i:j]是否是回文
 */
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.length();
        int max_start = 0, max_end = 0;
        int max_len = 1;

        vector<vector<bool>> dp(len, vector<bool>(len, false));

        //注意i，j的遍历方向
        for (int i = len -1; i >= 0; --i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                //当前两个字符相等并且s[i+1][j-1]也是回文，或者中间就夹一个字符
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = true;
                    //记录最大长度
                    if (j - i + 1 > max_len)
                    {
                        max_len = j - i + 1;
                        max_start = i;
                        max_end = j;
                    }
                }
            }
        }

        return s.substr(max_start, max_len);
    }
};
#endif