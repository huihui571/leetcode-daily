/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 1438-绝对差不超过限制的最长连续子数组.cpp 
*   Author      : huihui571
*   Created date: 2021-02-21
*   Description : 给你一个整数数组 nums ，和一个表示限制的整数 limit，请你返回最长连续子数组的长度，该子数组中的任意两个元素之间的绝对差必须小于或者等于 limit 。
*   如果不存在满足条件的子数组，则返回 0 。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 滑动窗口
 * 为了方便统计当前窗口内的最大值与最小值，需要使用高级的数据结构。
 * 1. 使用两个单调队列，分别维护可能的最大值和最小值。参考jz59
 * 2. 使用有序的数据结构，如红黑树。c++中是set和multiset
 */
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 0;
        multiset<int> s;
        int left = 0, right = 0;

        while (right < nums.size()) {
            s.insert(nums[right]);

            while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[left]));
                left++;
            }

            res = max(res, right - left + 1);
            right++;
        }

        return res;
    }
};
