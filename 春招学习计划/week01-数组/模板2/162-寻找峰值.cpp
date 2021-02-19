/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 162-寻找峰值.cpp 
*   Author      : huihui571
*   Created date: 2021-01-24
*   Description : 峰值元素是指其值大于左右相邻值的元素。给你一个输入数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
*   你可以假设 nums[-1] = nums[n] = -∞ 。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 比较节点和它的右邻居，以判断当前在上升区间还是下降区间
 * 这种要访问右邻居的，要保证循环中始终至少有两个元素，所以left<right
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        //后处理，这里最后的left就是答案
        return left;
    }
};
