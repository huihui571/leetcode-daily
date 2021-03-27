/*<FH+>************************************************************************
*   Editor     : Clion
*   File name  : 132-分割回文串II.cpp
*   Author     : huihui571
*   Created date: 2021-03-25
*   Description : 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。
*   返回符合要求的 最少分割次数 。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 动态规划
 * 先预处理，以便快速判断一个字串是否是回文。
 * dp[i]表示s[0..i]的最少分割次数
 */
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        //预处理。注意i,j的起点及遍历方向
        vector<vector<bool>> isP(n, vector<bool>(n, true));
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                isP[i][j] = (s[i] == s[j]) && isP[i + 1][j - 1];
            }
        }

        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = i;      //初始假设每一个字符都要分割，i个字符最多分割i次
        }

        for (int i = 1; i < n; ++i) {
            if (isP[0][i]) {
                dp[i] = 0;      //如果本身是回文则不用分割了
                continue;
            }
            //枚举i前面的位置j，若[j..i]是回文，则转化为子问题[0..j]的最少分割次数
            //前面的j个位置dp[j]取最小值
            for (int j = 0; j < i; ++j) {
                if (isP[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};
