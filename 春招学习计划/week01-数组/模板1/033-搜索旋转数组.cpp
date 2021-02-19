/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 033-搜索旋转数组.cpp 
*   Author      : huihui571
*   Created date: 2021-01-23
*   Description : 升序排列的整数数组 nums 在预先未知的某个点上进行了旋转（例如， [0,1,2,4,5,6,7] 经旋转后可能变为 [4,5,6,7,0,1,2] ）。
*   请你在数组中搜索 target ，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
* 先通过比较mid和端点（这里左右都行）来判断哪一部分有序，然后再对有序和有转折两种情况来
* 讨论mid和target大小关系，定位区间。
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            //先判断哪段有序
            if (nums[mid] >= nums[left]) {
                //把握住有序的一半
                if (target >= nums[left] && target < nums[mid]){
                    right = mid - 1; 
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};

