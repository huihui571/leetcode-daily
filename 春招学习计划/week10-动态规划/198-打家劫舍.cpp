/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 198-打家劫舍.cpp
*   Author      : huihui571
*   Created date: 2021-03-24
*   Description : 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
*   如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
*   给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#if 0
/**
 * 一维状态数组
 * 如果不偷当前的话，dp[i] = dp[i-1]
 * 如果偷当前的话，那一定不偷上一个，状态只能从i-2转移过来，dp[i] = dp[i-2] + nums[i]
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int pre = 0;
        int ppre = 0;
        for (int i = 0; i < n; ++i) {
            int cur = max(pre, ppre + nums[i]);
            ppre = pre;
            pre = cur;
        }
        return pre;
    }
};
#endif

#if 1
/**
 * 二维状态数组 + 状态压缩
 * 通过 %2的方式控制数组下标，依然保留dp数组的形式
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<vector<int>> dp(2, vector<int>(2));
        dp[0][0] = 0;   //不偷
        dp[0][1] = nums[0]; //偷

        for (int i = 1; i < n; i++)
        {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1]);
            dp[i % 2][1] = dp[(i - 1) % 2][0] + nums[i];           
        }

        return max(dp[(n - 1) % 2][0], dp[(n - 1) % 2][1]);
    }
};
#endif
