/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 283-移动零.cpp
*   Author      : huihui571
*   Created date: 2021-03-09
*   Description : 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 *   说明:
 *   必须在原数组上操作，不能拷贝额外的数组。
 *   尽量减少操作次数。
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 先统计0的个数，然后用双指针移动非零元素，最后在数组最后面的相应元素替换成零。
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_cnt = 0;
        for (int num : nums) {
            zero_cnt += num == 0 ? 1 : 0;
        }

        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }

        for (int i = 0; i < zero_cnt; ++i) {
            nums[nums.size() - 1 - i] = 0;
        }
    }
};

