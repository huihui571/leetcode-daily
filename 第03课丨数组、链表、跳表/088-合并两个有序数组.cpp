/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 088-合并两个有序数组.cpp
*   Author      : huihui571
*   Created date: 2020-07-06
*   Description : 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
说明:
初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
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
 * 与“021-合并两个有序链表”一样的模板
 */
class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int n1 = m - 1;
        int n2 = n - 1;
        int i = m + n - 1;
        //从后面开始，每次选两个数组中较大元素加入结果
        while(n1 >= 0 && n2 >= 0)
        {
            if (nums1[n1] >= nums2[n2])
            {
                nums1[i--] = nums1[n1--];
            }
            else
            {
                nums1[i--] = nums2[n2--];
            }
        }

        //nums1,nums2至多只剩下一个
        while (n1 >= 0)
        {
            nums1[i--] = nums1[n1--];
        }
        while (n2 >= 0)
        {
            nums1[i--] = nums2[n2--];
        }

    }
};

#if 0
/**
 * 未accept,时间复杂度有点高，为O(n*log(m)*m)，没有利用到nums2有序的条件。
 */
class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        //为nums2的每一个元素寻找插入位置
        for (int i = 0; i < n; ++i)
        {
            int target = nums2[i];
            search_insert(nums1, m, target);
        }

    }

    //将target插入有序数组的合适位置，二分法模板
    void search_insert(vector<int>& nums, int len, int target)
    {
        int left = 0;
        int right = len - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (target == nums[mid])
            {
                insert_in_nums(nums, len, mid + 1, target);
            }
            else if (target > nums[mid])
            {
                left = mid + 1;
            }
            else if (target < nums[mid])
            {
                right = mid - 1;
            }
        }

        //插入
        int pos = target >= nums[left] ? left + 1 : left - 1;   //此时left==right，根据target和当前元素大小，决定插入其之前还是之后
        insert_in_nums(nums, len, pos, target);
    }

    //在数组指定位置插入一个元素
    void insert_in_nums(vector<int>& nums, int len, int pos, int target)
    {
        for (int i = len; i > pos; i--)
        {
            nums[i] = nums[i - 1];      //后移一位
        }
        nums[pos] = target;             //插入
    }
};
#endif

