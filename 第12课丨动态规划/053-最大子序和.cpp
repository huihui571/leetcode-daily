/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 053-最大子序和.cpp
*   Author      : huihui571
*   Created date: 2020-09-25
*   Description : 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例:
输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
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
#include <algorithm>

using namespace std;

/**
 * 动态规划
 * dp[k]是长度为k的子问题的解
 */
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        //定义dp数组，dp数组中的每个值dp[i]代表着以nums[i]为结尾的最大子序和
        vector<int> dp(nums.size(), 0);

        //以nums[0]结尾的最大子序和就是nums[0]
        dp[0] = nums[0];

        //遍历，通过状态转移方程求得dp[i]的最大子序和
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);  //dp[i]的最大子序和要么是自成一派最大，要么就是当前值加上前面i - 1个数的最大子序和
        }

        //dp数组中的最大值就是答案
        return *(max_element(dp.begin(), dp.end()));
    }
};