/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 912-排序数组.cpp
*   Author      : huihui571
*   Created date: 2021-03-10
*   Description : 给你一个整数数组 nums，请你将该数组升序排列
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    //插入
    void insertSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            int tmp = nums[i];

            int j = i;  //从i往前找
            while (j > 0 && tmp < nums[j - 1]) {
                nums[j] = nums[j - 1];
                j--;
            }
            nums[j] = tmp;  //插入
        }
    }

    //二分插入

    //快排
    void quickSort(vector<int>& nums, int start, int end) {
        if (end <= start)
            return;

        int pivot = partition(nums, start, end);
        quickSort(nums, start, pivot - 1);
        quickSort(nums, pivot + 1, end);
    }

    int partition(vector<int>& nums, int start, int end) {
        int pivot = nums[start];
        int mask = start;

        for (int i = start + 1; i <= end; ++i) {
            if (nums[i] < pivot) {
                mask++;
                swap(nums[i], nums[mask]);
            }
        }
        swap(nums[mask], nums[start]);
        return mask;
    }

    //冒泡
    void bubbleSort(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            bool flag = false;
            for (int j = nums.size() - 1; j > i; --j) {
                if (nums[j - 1] > nums[j]) {
                    swap(nums[j - 1], nums[j]);
                    flag = true;
                }
            }
            if (!flag)
                return;
        }
    }

    //简单选择

    //堆排序
};
