/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 033-搜索旋转排序数组.cpp
*   Author      : huihui571
*   Created date: 2020-09-16
*   Description : 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是 O(log n) 级别。
*
*<FH->***************************************************************/  
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * 时间复杂度O(logn)，所以只有二分法符合要求。
 * 由于数组是生序的，将mid中间值分别与首尾值比较，便可得出左右哪一部份是有序的,利用有序的一半可以确定target范围。
 */
class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        if (nums.empty())
            return -1;
        if (nums.size() == 1)
            return nums[0] == target ? 0 : -1;

        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[mid] >= nums[0])   //左半部分有序
            {
                if (target >= nums[left] && target < nums[mid]) //target在左半部分
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else //右半部分有序
            {
                if (target > nums[mid] && target <= nums[nums.size() - 1])
                {
                    left = mid + 1;   
                }
                else
                {
                    right = mid - 1;
                }
            }
        } 

        return -1;
    }
};