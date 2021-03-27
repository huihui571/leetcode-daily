/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 53-II-0～n-1中缺失的数字.cpp
*   Author      : huihui571
*   Created date: 2021-01-02
*   Description : 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
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
 * 1. 首先想到对号入座法。但是对号入座无论是开一个计数数组还是在原地交换，都至少O(n)的时间复杂度，因为没有利用到题目数组有序的条件。
 * 2. 二分查找。缺失的m正好是数组中第一个数值和下标不相等的元素，问题转换为查找排序数值中第一个值和下标不相等的元素。
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] != mid) {
                if (mid == 0 || nums[mid - 1] == mid - 1)       //注意边界
                    return mid;     //缺失的数，不在nums里边，返回下标(下标和值相等)
                else
                    right = mid - 1;
            }
            else if (nums[mid] == mid) {
                left = mid + 1;
            }
        }
        if (left == nums.size())    //特殊情况，缺失的是最后一个数
            return left;

        return -1;
    }
};
