/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 169-多数元素.cpp
*   Author      : huihui571
*   Created date: 2021-03-11
*   Description : 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 n/2 的元素。
*   你可以假设数组是非空的，并且给定的数组总是存在多数元素。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 1. 排序
 * 2. 哈希表计数
 * 3. 摩尔投票
 * 4. 快速选择找中位数
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n / 2);
    }

    int quickSelect(vector<int>& nums, int left, int right, int k) {
        int mid = partition(nums, left, right);

        while (left < right) {
            if (mid == k)
                return nums[mid];
            else if (mid < k)
                left = mid + 1;
            else
                right = mid - 1;
            mid = partition(nums, left, right);
        }
        return nums[left];
    }
    int partition(vector<int>& arr, int left, int right) {
        srand((int)time(0));
        int index = left + rand() % (right - left + 1);
        swap(arr[left], arr[index]);
        int pivot = arr[left];
        int mask = left;    //小于pivot元素范围

        for (int i = left + 1; i <= right; ++i) {
            if (arr[i] < pivot) {
                mask++;
                swap(arr[mask], arr[i]);
            }
        }

        swap(arr[mask], arr[left]);
        return mask;
    }
};

