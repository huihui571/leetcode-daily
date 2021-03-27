/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 42-连续子数组的最大和.cpp
*   Author      : huihui571
*   Created date: 2020-12-26
*   Description : 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
要求时间复杂度为O(n)。
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
 * 注意结果是dp[n]还是maxof(dp)
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> dp(n);
//        dp[0] = nums[0];
//
//        for (int i = 1; i < n; ++i) {
//            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
//        }
//
//        return *max_element(dp.begin(), dp.end());

        int n = nums.size();
        int res = nums[0];
        int max_res = res;

        for (int i = 1; i < n; ++i) {
            res = max(res + nums[i], nums[i]);
            if (res > max_res)
                max_res = res;
        }

        return max_res;
    }
};
