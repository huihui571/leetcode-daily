/*<FH+>***************************************************************
*   Editor      : Visual Studio 2019
*   File name   : 416-分割等和子集.cpp
*   Author      : huihui571
*   Created date: 2020-11-28
*   Description : 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
* 示例 1: 
* 输入: [1, 5, 11, 5]
* 输出: true
* 解释: 数组可以分割成 [1, 5, 5] 和 [11].
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

#if 0
/**
* 子集划分问题是典型的背包问题变种，可以转化为：
* 给一个可装载重量为sum/2的背包和N个物品，每个物品的重量为nums[i]。现在让你装物品，是否存在一种装法，能够恰好将背包装满？
* dp[i][j] = x表示，对于前i个物品，当前背包的容量为j时，若x为true，则说明可以恰好将背包装满，若x为false，则说明不能恰好将背包装满。
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 != 0)
            return false;   //和为奇数时，不能划分为两个和相等的子集

        int n = nums.size();
        sum = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        //base case
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;        //背包没有空间的时候，相当于总是装满的
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (j - nums[i - 1] < 0) {
                    dp[i][j] = dp[i - 1][j];        //背包容量不足，不能装
                }
                else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];   //装或者不装，只要有一个选择能满足，当前就能满足，所以用或
                }
            }
        }

        return dp[n][sum];
    }
};
#endif

#if 1
/**
* 空间优化，进行状态压缩
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int num : nums) sum += num;
        if (sum % 2 != 0)
            return false; 
        sum = sum / 2;
        vector<bool> dp(sum + 1, false);
        //base case
        dp[0] = true;

        //唯一需要注意的是j应该从后往前反向遍历，因为每个物品（或者说数字）只能用一次，以免之前的结果影响其他的结果。
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= 0; j--) {
                if (j - nums[i] >= 0)
                    dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[sum];
    }
};
#endif