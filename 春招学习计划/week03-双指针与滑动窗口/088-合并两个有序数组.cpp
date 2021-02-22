/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 088-合并两个有序数组.cpp 
*   Author      : huihui571
*   Created date: 2021-02-06
*   Description : 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
*   初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 双指针，与合并两个有序链表一样的模板，只是注意从后往前合并。
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            }
            else {
                nums1[k--] = nums2[j--];
            }
        }

        while (i >= 0) {
            nums1[k--] = nums1[i--];
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
        
        return;
    }
};
