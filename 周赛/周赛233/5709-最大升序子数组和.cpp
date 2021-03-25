/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 5709-最大升序子数组和.cpp 
*   Author      : huihui571
*   Created date: 2021-03-21
*   Description : 给你一个正整数组成的数组 nums ，返回 nums 中一个 升序 子数组的最大可能元素和。
*   子数组是数组中的一个连续数字序列。
*   已知子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，若对所有 i（l <= i < r），numsi < numsi+1 都成立，则称这一子数组为 升序 子数组。注意，大小为 1 的子数组也视作 升序 子数组。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 动态规划
 */
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + nums[i];
            }
            else {
                dp[i] = nums[i];
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
