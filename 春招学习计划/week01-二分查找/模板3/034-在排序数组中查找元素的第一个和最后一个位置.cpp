/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 034-在排序数组中查找元素的第一个和最后一个位置.cpp 
*   Author      : huihui571
*   Created date: 2021-01-24
*   Description : 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
*   如果数组中不存在目标值 target，返回 [-1, -1]。
*   进阶：你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 用二分查找分别找target出现的第一个和最后一个位置
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
            return {-1, -1};
        int start = findFirst(nums, target);
        int end = findLast(nums, target);

        return {start, end};
    }

    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return nums[left] == target ? left : -1;
    }

    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid;
            }
        }

        return nums[left] == target ? left : -1;
    }
};
