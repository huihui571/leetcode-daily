/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 10-II-青蛙跳台阶问题.cpp
*   Author      : huihui571
*   Created date: 2020-11-28
*   Description : 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
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

/**
 * 跳上第n级台阶的方法 = 从第n-1级跳上来的方法数 + 从第n-2级跳上来的方法数
 * 即f(n) = f(n - 1) + f(n - 2)
 * 先用递归自顶向下思考，再用动态规划优化
 */
class Solution {
public:
    int numWays(int n) {
        if (n <= 1)
            return 1;

        int fn_1 = 1;   //跳上0级台阶有一种
        int fn_2 = 1;   //1级也有一种
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