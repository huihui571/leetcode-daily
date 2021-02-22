/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 448-找到所有数组中消失的数字.cpp 
*   Author      : huihui571
*   Created date: 2021-02-13
*   Description : 给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
*   找到所有在 [1, n] 范围之间没有出现在数组中的数字。
*   您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 对号入座
 */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};
