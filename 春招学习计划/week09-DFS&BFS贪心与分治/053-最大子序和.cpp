/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 053-最大子序和.cpp
*   Author      : huihui571
*   Created date: 2021-03-23
*   Description : 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
*   
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 1. 贪心
 * 对于含有正数的序列而言,最大子序列肯定是正数,所以头尾肯定都是正数.我们可以从第一个正数开始算起,每往后加一个数便更新一次和的最大值;
 * 当当前和成为负数时,则表明此前序列无法为后面提供最大子序列和,因此必须重新确定序列首项.
 * 2. 动态规划
 * dp[i] = max(dp[i - 1] + nums[i], nums[i])
 * 其实这里的dp[i - 1]可以看作下面的sum，贪心和动态规划形式类似，但思路完全不同
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int sum = 0;

        for (int num : nums) {
            if (sum > 0) {
                sum += num;     //大于0的sum对后面有贡献，所以加上
            }
            else {
                sum = num;      //抛弃前面的sum
            }
            res = max(res, sum);
        }

        return res;
    }
};