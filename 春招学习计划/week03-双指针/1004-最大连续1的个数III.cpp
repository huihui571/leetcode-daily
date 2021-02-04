/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 1004-最大连续1的个数III.cpp 
*   Author      : huihui571
*   Created date: 2021-02-03
*   Description : 给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。
*   返回仅包含 1 的最长（连续）子数组的长度。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 其实这个题目等价于：寻找一个区间，该区间最多只能包含k个0，求该区间的最大长度。
 * 滑动窗口（双指针）
 */
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int res = 0;
        int count = 0;  //记录0的个数
        int left = 0, right = 0;

        while (right < A.size()) {
            count += A[right++] == 0 ? 1 : 0;   //区间右扩，同时统计0的个数
            while (count > K) {
                count -= A[left++] == 0 ? 1 : 0; //收缩左边界，直到0个数不超过K
            }
            res = max(res, right - left + 1);
        }

        return res;
    }
};
