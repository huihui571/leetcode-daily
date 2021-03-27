/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 213-打家劫舍II.cpp
*   Author      : huihui571
*   Created date: 2020-10-10
*   Description : 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
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

#if 1
/**
 * 环状排列意味着第一个房子和最后一个房子中只能选择一个偷窃，因此可以把此环状排列房间问题约化为两个单排排列房间子问题(198)：
 * 在不偷窃第一个房子的情况下（即 nums[1:]），最大金额是p1；
 * 在不偷窃最后一个房子的情况下（即 nums[:n-1]），最大金额是p2。
 * 综合偷窃最大金额： 为以上两种情况的较大值，即 max(p1,p2)。
 */
class Solution
{
public:
    int rob(vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        
        int p1 = rob_sub(nums, 0, nums.size()-1);   //要第一个
        int p2 = rob_sub(nums, 1, nums.size());     //不要第一个

        return max(p1, p2);
    }

    /*
    动态转移方程是：
    f(n)=max(nums[n]+f(n-2),f(n-1))
    pre:f(k-2)
    cur:f(k-1)
    */
    int rob_sub(vector<int>& nums, int start, int end)
    {
        int ppre = 0;   //n-2
        int pre = 0;    //n-1

        for (int i = start; i < end; ++i)
        {
            int cur = max(nums[i] + ppre, pre);
            ppre = pre;
            pre = cur;
        }
        return pre;
    }
};
#endif

#if 0
/**
 * 二维dp,第二维分别代表偷第一个和不偷时两种情况问题的解。
 */
class Solution
{
public:
    int rob(vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        vector<vector<int>> dp(nums.size(), vector<int>(2));
        //不偷第一个
        dp[0][0] = 0;       
        dp[1][0] = nums[1]; //第二个一定偷
        //偷第一个
        dp[0][1] = nums[0]; 
        dp[1][1] = dp[0][1];    //第二个一定不偷

        for (int i = 2; i < nums.size() -1; ++i)
        {
            dp[i][0] = max(dp[i-2][0] + nums[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-2][1] + nums[i], dp[i-1][1]);
        }
        //不偷第一个则最后一个又分偷不偷两种
        dp[nums.size()-1][0] = max(dp[nums.size()-1-1][0], dp[nums.size()-1-2][0] + nums[nums.size()-1]);
        //偷第一个的情况，      
        dp[nums.size()-1][1] = dp[nums.size()-2][1];

        return max(dp[nums.size()-1][0], dp[nums.size()-1][1]);
    }
};
#endif