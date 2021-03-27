/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 57-I-和为s的两个数字.cpp
*   Author      : huihui571
*   Created date: 2021-01-03
*   Description : 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。
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
 * 1. 哈希表。需要O(n)的空间复杂度，没有利用到有序的条件。
 * 2. 双指针。首尾双指针，根据当前和判断移动哪一个指针来缩小搜索范围。
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int i = 0, j = nums.size() - 1;

        while (i < j) {
            long sum = nums[i] + nums[j];   //这里要不要用long要根据测试用例的范围来选择
            if (sum == target) {
                return {nums[i], nums[j]};
            }
            else if (sum < target) {
                i++;
            }
            else {
                j--;
            }
        }

        return {-1, -1};
    }
};
