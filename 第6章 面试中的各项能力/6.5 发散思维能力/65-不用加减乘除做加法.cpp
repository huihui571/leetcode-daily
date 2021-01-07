/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 65-不用加减乘除做加法.cpp
*   Author      : huihui571
*   Created date: 2021-01-07
*   Description : 写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
*   提示：a, b 均可能是负数或 0
*        结果不会溢出 32 位整数
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
 * 位运算
 * 加法分为三步，1：只相加不考虑进位 2：只计算进位 3：把前两部的结果相加
 * 二进制下，第1步刚好和异或的结果一样，第2步刚好和按位与的结果一样，然后再把它们相加就是最终结果了
 */
class Solution {
public:
    int add(int a, int b) {
        // if (b == 0)
        //     return a;
        // int sum = a ^ b;
        // int carry = (unsigned int)(a & b) << 1;
        // return add(sum, carry);

       while (b != 0) {            //当没有进位时退出循环
           int sum = a ^ b;            //无进位和
           int carry = (unsigned int)(a & b) << 1; // C++ 不允许负数进行左移操作，故要加 unsigned int

           a = sum;
           b = carry;
       }
       return a;
    }
};
