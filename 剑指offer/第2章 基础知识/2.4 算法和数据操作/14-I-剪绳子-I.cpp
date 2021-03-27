/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 14-剪绳子-I.cpp
*   Author      : huihui571
*   Created date: 2020-12-02
*   Description : 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
*   每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
*   例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
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
 * 动态规划
 * dp[i]表示绳子长度为i时得到的最大乘积
 * dp[0]=dp[1]=0, dp[2]=1
 */
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 0;
        dp[2] = 1;

        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                // int tmp = max(j * (i - j), j * dp[i - j]);
                // dp[i] = max(dp[i], tmp);
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));   
            }
        }

        return dp[n];
    }
};
#endif

#if 1
/**
 * 贪心算法
 * (数学证明略)当n > 4时， 尽可能多剪长度为3的绳子；当剩下的绳子长度为4时，把绳子剪成两段长度为2的绳子。
 */
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4)
            return n - 1;   //绳子长度为2或3时，最大乘积是1和2

        int res = 1;
        while (n > 4) {
            n = n - 3;      //尽可能多剪长度为3的绳子
            res = res * 3;  //计算每段的乘积
        }

        return n * res;
    }
};
#endif