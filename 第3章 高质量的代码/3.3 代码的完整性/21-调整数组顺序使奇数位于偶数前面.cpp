/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 21-调整数组顺序使奇数位于偶数前面.cpp
*   Author      : huihui571
*   Created date: 2020-12-06
*   Description : 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
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
 * 1. 双指针法，时间复杂度O(n)，空间复杂度O(1)
 * 2. 辅助数组法，时间复杂度O(n)，空间复杂度O(n)
 */
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.empty())
            return {};

        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (left < right && !isEven(nums[left])) {   //如果指向奇数就跳过
                left++;
            }
            while (left < right && isEven(nums[right])) {   //如果指向偶数就跳过
                right--;
            }
            swap(nums, left, right);    //left指向偶数，right指向奇数，交换它们
        }

        return nums;
    }

    //判断val是否为偶数，采用位运算
    bool isEven(int val) {
        return (val & 0x01) == 0;
    }

    void swap(vector<int>& nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
};
