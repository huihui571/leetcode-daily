/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 658-找到K个最接近的元素.cpp 
*   Author      : huihui571
*   Created date: 2021-01-25
*   Description : 给定一个排序好的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。
*   整数 a 比整数 b 更接近 x 需要满足：
*       |a - x| < |b - x| 或者
*       |a - x| == |b - x| 且 a < b
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 1.排序。将数组中元素按照与x之差绝对值排序，取前k个元素。需自定义cmp。
 * 2.双指针。从两侧逐步缩小区间，每次排除掉离x较远的那个元素。
 * 2.二分查找。因为要查找的区间长度K是已知的，所以不需要查找两个端点，只要查找左端点就行了。
 */
#if 0
//双指针
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //x小于等于第一个数，那么结果就是数组最左边的K个数
        if (x <= arr[0]) {
            return vector<int>(arr.begin(), arr.begin() + k);
        }
        //x大于等于最后一个数，那么结果就是数组最右边的K个数
        if (x >= arr.back()) {
            return vector<int>(arr.end() - k, arr.end());
        }
        
        int i = 0, j = arr.size() - 1;
        //离目标较远的那一侧指针向里缩,如果距离相等那保留左侧
        while (j - i + 1 > k) {
            if (arr[j] - x >= x - arr[i]) {
                j--;
            }  
            else {
                i++;
            }
        }

        return vector<int>(arr.begin() + i, arr.begin() + j + 1);
    }
};
#else
//二分查找左边界。转化为找一个位置使x位于[mid, mid + k - 1]之间。
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;   //左边界的最右边可以取到len - k

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
#endif
