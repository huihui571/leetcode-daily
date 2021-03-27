/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 198-打家劫舍.cpp
*   Author      : huihui571
*   Created date: 2020-10-06
*   Description : 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
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

#if 0
/**
 * dp数组记录到当前位置的时候，能偷到的最高金额。有偷当前这家或者不偷两种情况。
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

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);  //偷0或1

        for (int i = 2; i < nums.size(); ++i)
        {
            //如果偷当前这个dp[i]=dp[i-2]+n[i]，如果不偷当前dp[i]=dp[i-1]
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }

        // return *(max_element(dp.begin(), dp.end()));
        return dp[nums.size() - 1];
    }
};
#endif

#if 0
/**
 * 空间优化，每次只用到了i-1和i-2两步的状态，不需要保留全部的状态。
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

        int pre = 0; //dp[i-1]
        int ppre = 0; //dp[i-2]
        for (int i = 0; i < nums.size(); ++i)
        {
            //如果偷当前这个dp[i]=dp[i-2]+n[i]，如果不偷当前dp[i]=dp[i-1]
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
 * 二维dp,第一维记录到当前位置为止偷的结果。第二维长度维2分别是偷当前和不偷时的结果
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

        vector<vector<int>> dp(nums.size(), vector<int>(2));    //第二维0：不偷当前，1:偷当前
        dp[0][0] = 0;       //不偷第0个
        dp[0][1] = nums[0]; //偷第0个

        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]); //当前不偷，结果可能是上一个偷或不偷的结果
            dp[i][1] = dp[i-1][0] + nums[i];    //当前偷，则上一个一定不偷
        }
        
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};
#endif