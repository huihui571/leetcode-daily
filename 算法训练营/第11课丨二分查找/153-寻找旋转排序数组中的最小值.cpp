/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 153-寻找旋转排序数组中的最小值.cpp
*   Author      : huihui571
*   Created date: 2020-09-21
*   Description : 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
请找出其中最小的元素。
你可以假设数组中不存在重复元素。
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

#if 0
/**
 * 二分法
 * 比较左值就行不通，如果求最大值可以比较左值
 * 不要考虑哪一部分有序，画出图来，分几种情况，跟左值比较那么最大值的位置可以归纳为两种情况，每次
 * 缩小一半查找范围
 */
class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[left])     //最大值一定在左半部分
            {
                right = mid - 1;
            }
            else if (nums[mid] >= nums[left])   //最大值一定在右半部分
            {
                left = mid;
            }
        }

        return nums[left];
    }
};
#endif

#if 1
/**
 * 二分法
 * 比较中值与右值。在while循环内，nums[mid]要么大于要么小于nums[right]，不会等于
 */
class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right])     //左半部分有序，最小值在右半部分
            {
                left = mid + 1;  
            }
            else   //右半部分有序，最小值在左半部分
            {
                right = mid;        //mid有可能是最小值
            }
        }

        return nums[left];
    }
};
#endif