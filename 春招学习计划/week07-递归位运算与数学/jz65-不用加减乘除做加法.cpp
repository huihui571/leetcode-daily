/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : jz65-不用加减乘除做加法.cpp
*   Author      : huihui571
*   Created date: 2021-03-05
*   Description : 写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 拆解bit按位来算。分为无进位部分和有进位部分，利用赋值给a,b或者add函数来实现两部分相加。
 */
class Solution {
public:
    int add(int a, int b) {

        while (b) {
            int c = a ^ b;
            int flag = (unsigned int)(a & b) << 1; //c++负数不允许左移

            //在下一个循环中计算c + flag
            a = c;
            b = flag;
        }

        return a;
    }
};

