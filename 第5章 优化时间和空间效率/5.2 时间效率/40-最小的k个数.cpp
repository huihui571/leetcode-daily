/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 40-最小的k个数.cpp
*   Author      : huihui571
*   Created date: 2020-12-21
*   Description : 输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
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

using namespace std;

/**
 * 快速选择
 * 退化的快速排序，partition函数来找第k大的数，那么根据快排partition的定义，这个数左边的k-1个数都是小于它的，于是我们就
 * 得到了最小的前k个数，只是这k个数的顺序不一定是有序的。
 * 时间复杂度O(n)，最坏O(n2)，空间复杂度O(logn)
 */
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if (arr.empty() || k == 0)
            return res;
        quickSelection(res, arr, 0, arr.size() - 1, k);

        return res;
    }

    void quickSelection(vector<int>& res, vector<int>& arr, int left, int right, int k) {
        //partition函数将一个区间内所有小于下标为 j 的数放在 j 左边，大于下标为 j 的数放在 j 右边
        int j = partition(arr, left, right);

        //若j等于k-1，则划分的正好是前k个数
        if (j == k - 1) {
            for (int i = 0; i < k; ++i) {
                res.push_back(arr[i]);      //arr[0]到arr[j]就是答案
            }
            return;
        }
        //若j小于k-1，将区间变成[j+1, right]；反之，变成[left, j-1]
        return j < k - 1 ? quickSelection(res, arr, j + 1, right, k) : quickSelection(res, arr, left, j - 1, k);
    }

    //partition函数，单变循环，比较简单
    int partition(vector<int>& arr, int left, int right) {
        int pivot = arr[left];
        int mask = left;        //哨兵，记录小于基准元素的区域边界

        //只考虑把小于基准的元素往前移动
        for (int i = left + 1; i <= right; ++i) {
            if (arr[i] < pivot) {
                mask++;                          //给兄弟腾一个位置
                swap(arr[i], arr[mask]);  //进来
            }
        }

        swap(arr[left], arr[mask]);     //pivot归位

        return mask;
    }

#if 0
    //partition函数，双边循环法
    int partition(vector<int>& arr, int left, int right) {
        //取第一个位置(也可以随机选择位置，然后交换到第1个来)作为基准元素
        int pivot = arr[left];
        int i = left;
        int j = right;

        //先扫右边后左边，等号放在左边，否则就不对了，可以模拟一下看看。这个根pivot放最前面有关。
        while (i < j) {
            //右边大于基准的不用动
            while (i < j && arr[j] > pivot) j--;
            //左边小于等于基准的不用动
            while (i < j && arr[i] <= pivot) i++;

            //否则，交换左右指针所指向的元素
            if (i < j)
                swap(arr[i], arr[j]);
        }
        //指针相遇的地方就是pivot应该在的位置，交换
        swap(arr[left], arr[i]);

        return i;
    }
#endif
    void swap(int& a, int& b) {
        int t = a;
        a = b;
        b = t;
    }
};
