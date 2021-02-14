/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 5676-生成交替二进制字符串的最少操作数.cpp 
*   Author      : huihui571
*   Created date: 2021-02-14
*   Description : 给你一个仅由字符 '0' 和 '1' 组成的字符串 s 。一步操作中，你可以将任一 '0' 变成 '1' ，或者将 '1' 变成 '0' 。
*   交替字符串 定义为：如果字符串中不存在相邻两个字符相等的情况，那么该字符串就是交替字符串。例如，字符串 "010" 是交替字符串，而字符串 "0100" 不是。
*   返回使 s 变成 交替字符串 所需的 最少 操作数
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 动态规划。
 * dp[i][0]表示以s[i]结尾并且s[i]='0'的子串最少操作次数
 * dp[i][1]表示以s[i]结尾并且s[i]='1'的子串最少操作次数
 */
class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
//        vector<vector<int>> dp(n, vector<int>(2, 0));
//        if (s[0] == '0') {
//            dp[0][0] = 0;
//            dp[0][1] = 1;           
//        }
//        else {
//            dp[0][0] = 1;
//            dp[0][1] = 0;
//        }
//
//
//        for (int i = 1; i < n; i++) {
//            if (s[i] == '1') {
//                dp[i][0] = dp[i - 1][1] + 1;
//                dp[i][1] = dp[i - 1][0];
//            }
//            else {
//                dp[i][0] = dp[i - 1][1];
//                dp[i][1] = dp[i - 1][0] + 1;
//            }
//        }
//        
//        return min(dp[n - 1][0], dp[n - 1][1]);

        int cur0 = 0, cur1 = 0, last0 = 0, last1 = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cur0 = last1 + 1;
                cur1 = last0;
                last0 = cur0;
                last1 = cur1;
            }
            else {
                cur0 = last1;
                cur1 = last0 + 1;
                last0 = cur0;
                last1 = cur1;
            }
        }

        return min(cur0, cur1);
    }
};
