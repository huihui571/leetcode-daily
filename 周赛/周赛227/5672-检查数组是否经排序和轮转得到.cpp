/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 5672-检查数组是否经排序和轮转得到.cpp 
*   Author      : huihui571
*   Created date: 2021-02-07
*   Description : 给你一个数组 nums 。nums 的源数组中，所有元素与 nums 相同，但按非递减顺序排列。
*   如果 nums 能够由源数组轮转若干位置（包括 0 个位置）得到，则返回 true ；否则，返回 false 。
*   源数组中可能存在 重复项 。
*   注意：我们称数组 A 在轮转 x 个位置后得到长度相同的数组 B ，当它们满足 A[i] == B[(i+x) % A.length] ，其中 % 为取余运算。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int time = 0;

        for (int i = 0; i < n; i++) {
            left = right;
            right = (right + 1) % n;
            if (nums[right] < nums[left]) {
                time++;
            }
        }

        return time <= 1;
    }
};
