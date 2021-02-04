/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 1745-回文串分割IV.cpp 
*   Author      : huihui571
*   Created date: 2021-02-01
*   Description : 给你一个字符串 s ，如果可以将它分割成三个 非空 回文子字符串，那么返回 true ，否则返回 false 。
*   当一个字符串正着读和反着读是一模一样的，就称其为 回文字符串 。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 动态规划。dp[i][j]表示字符串s[i...j]是否是回文串。
 * 先打表，得到得到整个字符串的回文信息之后，再去枚举三段里中间那段的start和end，返回答案。
 */
class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.length();
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));

        //预处理[i,j]是否是回文串
        //因为求dp[i][j]时要用到dp[i+1][j-1]，所以i倒着遍历
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    dp[i][j] = true;                               //baseCase只有一个字符的情况
                }
                else if (i + 1 == j) {
                    dp[i][j] = s[i] == s[j];                //baseCase只有两个字符，即i,j相邻的情况
                }
                else {
                    dp[i][j] = s[i] == s[j] && dp[i+1][j-1];  //其它情况，s[i]等于s[j]并且它们中间的子串也是回文 
                }
            }        
        }  

        // 枚举分割点[0,i],[i+1,j],[j+1][n-1]
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j ++) {
                if (dp[0][i] && dp[i + 1][j] && dp[j + 1][n - 1]) {
                    return true;
                }
            }
        }

        return false;
    }
};

