/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 153-寻找旋转排序数组中的最小值.cpp 
*   Author      : huihui571
*   Created date: 2021-01-24
*   Description : 假设按照升序排序的数组在预先未知的某个点上进行了旋转。例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] 。
*   请找出其中最小的元素
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 为什么必须比较比较mid和右端点？
 * 考虑最后剩下两个元素，一定是[最大值，最小值]这样。
 * 因为要求的最小值在右边，所以每次right=mid，比右端点；求最大值则反之(注意反过来时mid要向上取整)。
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
            else {
                right = mid;    //mid本身可能也是答案
            }
        }

        //后处理
        return nums[left];
    }
};
