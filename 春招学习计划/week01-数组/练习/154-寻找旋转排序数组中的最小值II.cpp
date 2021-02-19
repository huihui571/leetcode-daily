/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 154-寻找旋转排序数组中的最小值II.cpp 
*   Author      : huihui571
*   Created date: 2021-01-26
*   Description : 假设按照升序排序的数组在预先未知的某个点上进行了旋转。( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。请找出其中最小的元素。
*   注意数组中可能存在重复的元素
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 注意：数组中可能存在重复元素。
 * 难点：如果重复元素出现在数组的开头和结尾，那么当nums[mid] == nums[right]的时候，
 * 我们无法区分mid此时落在了左边还是右边，此时不能简单排除一半区间。
 * 但是既然mid和right相等，那么可以排除right这一个端点！
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else if (nums[mid] < nums[right]) {
                right = mid;
            }
            else {
                right--;
            }
        }

        return nums[left];
    }
};
