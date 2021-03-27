/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 300-最长上升子序列.cpp
*   Author      : huihui571
*   Created date: 2020-11-12
*   Description : 给定一个无序的整数数组，找到其中最长上升子序列的长度。
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
 * 1. 贪心 + 二分优化
 * 考虑一个简单的贪心，如果我们要使上升子序列尽可能的长，
 * 则我们需要让序列上升得尽可能慢，因此我们希望每次在上升子序列最后加上的那个数尽可能的小。
 * 定义数组end[]，end[i]记录长度为i的最长上升子序列的末尾值。
 * 对于nums中的每一个数，我们考虑是否将其加入最长上升子序列中，
 * 若：num[i] > 当前序列的末尾值
 *     则肯定把num[i]加入，序列长度+1
 * 否则：
 *     在之前的最长上升子序列中找到end[j - 1] < num[i] < end[j]的位置，更新end[j] = nums[i]
 */
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.empty())
            return 0;

        int n = nums.size();
        int len = 1;
        vector<int> end(n + 1);
        end[1] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            //注意这个末尾值的表达，长度不同的序列对应不同的末尾值，end[len]表示长度为len的最长上升子序列的末尾值
            //end每个位置存的只是末尾值一个值
            if (nums[i] > end[len]) 
            {
                end[++len] = nums[i];
            }
            else
            {
                /**
                 * 这一段在有序数组中查找第一个小于target的元素的位置
                 */
                // int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                // while (l <= r) {
                //     int mid = (l + r) >> 1;
                //     if (end[mid] < nums[i]) {
                //         pos = mid;
                //         l = mid + 1;
                //     } else {
                //         r = mid - 1;
                //     }
                // }
                // end[pos + 1] = nums[i];

                int pos = find_target(end.data(), 1, len, nums[i]);
                end[pos + 1] = nums[i];

            }
        }

        return len;
    }
    //二分查找寻找target左侧的第一个数
    int find_target(int nums[], int start, int end, int target)
    {
        int l = start, r = end, pos = 0;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] == target)
            {
                return mid - 1;
            }           
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
        } 
        return nums[l] < target ? l : l - 1;   
    }
};
#endif

#if 1
/**
 * dp[i]表示以第i个数字结尾的最长上升子序列长度，这样答案其实是dp数组的最大值
 * dp[i]=max(dp[j])+1,其中0≤j<i且num[j]<num[i]
 * 本题中dp_i的状态不一定由dp_i-1转移而来，而是由0...i-1中符合条件(num[j]<num[i])的最长的那个转移而来。
 */
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        int n = nums.size();
        vector<int> dp(n);

        for (int i = 0; i < n; ++i)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
#endif