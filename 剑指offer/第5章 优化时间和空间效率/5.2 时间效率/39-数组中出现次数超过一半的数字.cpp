/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 39-数组中出现次数超过一半的数字.cpp
*   Author      : huihui571
*   Created date: 2020-12-21
*   Description : 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <time.h>

using namespace std;

#if 0
/**
 * 1. 排序
 * 2. 哈希表
 * 3. 摩尔投票算法。核心思想是相互抵消，有一个数字出现次数超过数组长度一半，也就是说它的出现次数比剩下所有数字出现次数的和还要多，那么抵消
 * 到最后剩下的一定是这个超过一半的数字。
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
#if 0
        unordered_map<int, int> count;
        int max_count = INT32_MIN;
        int res = 0;
        for (int num : nums) {
            count[num]++;
            if (count[num] > max_count) {
                max_count = count[num];
                res = num;
            }
        }
        //res出现次数最多但不一定大于一半，检查一下
        return count[res] > nums.size() / 2 ? res : 0;
#endif
        if (nums.empty())
            return 0;
        int res = nums[0];      //假设nums[0]是答案
        int times = 1;          //为它设置次数
        for (int i = 1; i < nums.size(); ++i) {
            if (times == 0) {
                res = nums[i];
                times = 1;
            }
            else if (res == nums[i]) {
                times++;
            }
            else {
                times--;
            }
        }

        return res;
    }
};
#endif

#if 1
/**
 * 快速选择算法。出现次数超过一半，那它一定是排序后下标为len/2的数。即寻找数组中第k大的数，k=len/2
 * pivot随机选择，对于一些极端用例，可以避免超时。
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int start = 0;
        int end = nums.size() - 1;
        int target = nums.size() / 2;
        int mid = partition(nums, start, end);

        while (mid != target) {
            // 在右边继续查找
            if (mid < target) {
                start = mid + 1;
            } else {
                // 在左边继续查找
                end = mid - 1;
            }
            mid = partition(nums, start, end);
        }
        return nums[mid];
    }

    int partition(vector<int>& arr, int left, int right) {
        //随机选择pivot，再把它和第一个元素交换，剩下的操作不变
        srand((int)time(0));
        int index = left + rand() % (right - left + 1);
        swap(arr[left], arr[index]);
        int pivot = arr[left];
        int mask = left;          //哨兵，记录小于pivot元素的范围

        for (int i = left + 1; i <= right; ++i) {
            if (arr[i] < pivot) {
                mask++;                   //腾位置
                swap(arr[i], arr[mask]);  //进来
            }
        }
        swap(arr[left], arr[mask]);

        return mask;
    }
    // int partition(vector<int>& arr, int left, int right) {
    //     srand((int)time(0));
    //     int index = left + rand() % (right - left + 1);
    //     swap(arr[left], arr[index]);
    //     int pivot = arr[left];
    //     int i = left;
    //     int j = right;

    //     while (i < j) {
    //         while (i < j && arr[j] > pivot) j--;
    //         while (i < j && arr[i] <= pivot) i++;
    //         if (i < j)
    //             swap(arr[i], arr[j]);
    //     }

    //     //NOTE:关于上面循环为什么要先对j操作。最后退出大循环的时候，一定有i==j，而这个位置应该是pivot所在的位置。
    //     //又因为pivot选的左边第一个元素，所以这个位置需要是在小于等于pivot的一侧。因此在i和j相邻的时候，一定是需要j--来使得i和j相遇。
    //     swap(arr[left], arr[i]);
    //     return i;
    // }
};
#endif
