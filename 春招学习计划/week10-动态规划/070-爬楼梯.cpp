/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 070-爬楼梯.cpp
*   Author      : huihui571
*   Created date: 2021-03-22
*   Description : 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
*   每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
*   注意：给定 n 是一个正整数。
*   
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 动态规划
 */
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        int last_1 = 2;
        int last_2 = 1;
        int cur = 0;
        for (int i = 2; i < n; ++i) {
            cur = last_1 + last_2;
            last_2 = last_1;
            last_1 = cur;
        }

        return cur;
    }
};

