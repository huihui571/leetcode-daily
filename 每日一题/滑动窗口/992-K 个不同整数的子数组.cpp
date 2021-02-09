/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 992-K\ 个不同整数的子数组.cpp 
*   Author      : huihui571
*   Created date: 2021-02-09
*   Description : 给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。
*   （例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）
*   返回 A 中好子数组的数目。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 恰好由 K 个不同整数的子数组的个数 = 最多由 K 个不同整数的子数组的个数 - 最多由 K - 1 个不同整数的子数组的个数
 */
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return subarraysAtMostK(A, K) - subarraysAtMostK(A, K - 1);
    }

    //最多由 K 个不同整数的子数组的个数
    int subarraysAtMostK(vector<int>& A, int K) {
        int res = 0;
        unordered_map<int, int> freq;
        int left = 0, right = 0;
        int count = 0;  //当前窗口中不同整数个数

        while (right < A.size()) {
            if (freq[A[right]] == 0) {
                count++;
            }
            freq[A[right]]++;

            while (count > K) {
                freq[A[left]]--;
                if (freq[A[left]] == 0) {
                    count--;
                }
                left++;
            }
           //为什么可以新用子数组的长度即right - left来表示增加的子数组个数呢？
           //当满足条件的子数组从[A,B,C]增加到[A,B,C,D]时，新子数组的长度为4，
           //同时增加的子数组为[D],[C,D],[B,C,D],[A,B,C,D]也为4。
            res += right - left + 1;

            right++;
        }

        return res;
    }
};
