/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 10-I-斐波那契数列.cpp
*   Author      : huihui571
*   Created date: 2020-11-28
*   Description : 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1

*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        int fn_1 = 1;   //F(N - 1)
        int fn_2 = 0;   //F(N - 2)
        int fn = 0;

        for (int i = 2; i <= n; ++i)
        {
            fn = (fn_1 + fn_2) % 1000000007;

            fn_2 = fn_1;
            fn_1 = fn;  
        }

        return fn;
    }
};