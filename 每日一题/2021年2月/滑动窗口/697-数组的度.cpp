/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 697-数组的度.cpp 
*   Author      : huihui571
*   Created date: 2021-02-20
*   Description : 给定一个非空且只包含非负数的整数数组 nums，数组的度的定义是指数组里任一元素出现频数的最大值。
*   你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
* 滑动窗口
*/
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int res = INT32_MAX;
        int degree = getDegree(nums);
        int left = 0, right = 0;
        unordered_map<int, int> freq;

        while (right < nums.size()) {
            freq[nums[right]]++;

            while (freq[nums[right]] == degree) {
                res = min(res, right - left + 1);
                freq[nums[left]]--;
                left++;
            }
            
            
            right++;
        }

        return res;
    }

    int getDegree(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        int degree = 0;
        for (auto it = count.begin(); it != count.end(); it++) {
            degree = max(degree, it->second);
        }

        return degree;
    }
};
