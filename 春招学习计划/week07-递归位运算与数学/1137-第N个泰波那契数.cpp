/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 1137-第N个泰波那契数.cpp
*   Author      : huihui571
*   Created date: 2021-03-02
*   Description : 泰波那契序列Tn定义如下：
*   T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0的条件下 Tn+3 = Tn + Tn+1 + Tn+2
*   给你整数n，请返回第 n 个泰波那契数Tn 的值。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 使用map做备忘录
 */
class Solution {
    unordered_map<int, int> memo;
public:
    int tribonacci(int n) { 
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        if (memo.count(n))
            return memo[n];
        int cur = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        memo[n] = cur;

        return cur;
    }
};