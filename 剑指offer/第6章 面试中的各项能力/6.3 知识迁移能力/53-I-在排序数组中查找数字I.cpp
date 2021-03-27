/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 53-I-在排序数组中查找数字I.cpp
*   Author      : huihui571
*   Created date: 2021-01-02
*   Description : 统计一个数字在排序数组中出现的次数。
*   输入: nums = [5,7,7,8,8,10], target = 8
*   输出: 2
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
 * 排序数组，自然想到二分
 * 如果只用二分查找target的话，找到后还要向两边扫描，时间复杂度将是O(n)和直接顺序扫描差不多。
 * 所以考虑用二分算法直接查找target的起点和终点。
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = 0;

        int start_index = getStart(nums, target);
        int end_index = getEnd(nums, target);
        if (start_index != -1 && end_index != -1)
            res = end_index - start_index + 1;

        return res;
    }

    int getStart(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid - 1] != target)    //注意边界
                    return mid;
                else
                    right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }

    int getEnd(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) {
                if (mid == nums.size() - 1 || nums[mid + 1] != target)
                    return mid;
                else
                    left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
