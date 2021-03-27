/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 14-II-剪绳子II.cpp
*   Author      : huihui571
*   Created date: 2020-12-03
*   Description : 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
*   每段绳子的长度记为 k[0],k[1]...k[m - 1] 。请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？
*   例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
*   答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
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
 * 和上一题的区别是，测试样例涉及大数越界的问题，解决方式对是求余。
 * 大数相乘，一般都要求将输出结果对1000000007取模（取余）。为什么总是1000000007呢？
 * 1. 它足够大，使得加法运算后结果能落在int32范围内。
 * 2. 因为它是一个质数，对质数取模可以最大程度避免冲突。
 */
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4)
            return n - 1;

        long res = 1;
        while (n > 4) {
            n -= 3;
            res *= 3;
            res %= 1000000007;
        }

        return int(n * res % 1000000007);
    }
};