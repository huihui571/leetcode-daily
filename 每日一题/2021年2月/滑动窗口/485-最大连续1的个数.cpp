/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 485-最大连续1的个数.cpp 
*   Author      : huihui571
*   Created date: 2021-02-15
*   Description : 给定一个二进制数组， 计算其中最大连续1的个数。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 简单的滑动窗口
 */
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, count = 0;
        int left = 0, right = 0;

        while (right < nums.size()) {
            if (nums[right] == 1) {
                count++;
            }
            else {
                res = max(res, count);
                count = 0;
                left = right;
            }
            right++;
        }

        return max(res, count); //别忘了最后一段
    }
};
