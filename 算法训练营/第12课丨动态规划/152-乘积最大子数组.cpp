/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 152-乘积最大子数组.cpp
*   Author      : huihui571
*   Created date: 2020-09-28
*   Description : 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
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
 * 要分正负两种情况。当前值为负数可能和之前的负积相乘后反而更大，所以dp数组要同时存储
 * 每一步的最大正积和最大负积
 */
class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        if (nums.empty())
            return -1;
        if (nums.size() == 1)
            return nums[0];

        vector<int> dp_max(nums.size());
        vector<int> dp_min(nums.size());

        dp_max[0] = nums[0];      //正的最大
        dp_min[0] = nums[0];     //负的最大

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == 0)       //0单独讨论，也可以用max,min合并在下面
            {
                dp_max[i] = dp_max[i-1];
                dp_min[i] = dp_min[i-1];
            }
            //当前最大值，要么是n[i]自身，要么是正的n[i]*正的dp[i-1],要么是负的n[i]*负的dp[i-1]
            dp_max[i] = max(max(dp_max[i-1] * nums[i], dp_min[i-1] * nums[i]), nums[i]);
            //当前最大负值，要么是n[i]自身，要么是正的n[i]*负的dp[i-1],要么是负的n[i]*正的dp[i-1]
            dp_min[i] = min(min(dp_min[i-1] * nums[i], dp_max[i-1] * nums[i]), nums[i]);
        }

        //dp数组中最大的不一定在最后一步
        return *(max_element(dp_max.begin(), dp_max.end()));
    }
};