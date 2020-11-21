/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 493-翻转对.cpp
*   Author      : huihui571
*   Created date: 2020-11-08
*   Description : 给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。
你需要返回给定数组中的重要翻转对的数量。
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
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
 * 归并排序
 */
class Solution
{
public:
    int reversePairs(vector<int>& nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }

    //归并的同时做统计
    //每一层先获取左右两个子部分“内部”的结果，然后再统计这一层的结果，即两部分“之间”的结果
    int mergeSort(vector<int>& nums, int start, int end)
    {
        if (end <= start)
            return 0;

        int mid = (start + end) >> 1;
        int count = mergeSort(nums, start, mid) + mergeSort(nums, mid + 1, end);

        //统计这一层的结果，对于左半部分每个元素，统计右半部分它的符合要求逆序对数量
        int j = mid + 1;
        for (int i = start; i <= mid; i++)
        {
            while (j <= end && (long)nums[i] > (long)nums[j] * 2)
                j++;
            count += j - (mid + 1);
        }

        merge(nums, start, mid, end);

        return count;
    }
    //merge函数每次是对nums一部分进行操作，别忘了加上相对位移start
    void merge(vector<int>& nums, int start, int mid, int end)
    {
        vector<int> temp(end - start + 1);
        int i = start, j = mid + 1, k = 0;

        while (i <= mid && j <= end)
        {
            temp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++]; 
        }

        while (i <= mid)   temp[k++] = nums[i++];
        while (j <= end) temp[k++] = nums[j++];

        copy(temp.begin(), temp.end(), nums.begin() + start);
        // for (int p = 0; p < temp.size(); p++)
        // {
        //     nums[start + p] = temp[p];
        // }
    }
};