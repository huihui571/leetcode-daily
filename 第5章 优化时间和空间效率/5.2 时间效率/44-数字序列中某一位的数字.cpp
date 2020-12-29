/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 44-数字序列中某一位的数字.cpp.c
*   Author      : huihui571
*   Created date: 2020-12-29
*   Description : 数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
*   请写一个函数，求任意第n位对应的数字。
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
 * 不算0，序列的组成是这样的：9个1位数、90个2位数、900个3位数...
 * 先判断n属于几位数的区间，然后再在区间内部判断n落到哪一个数值，再判断落到这个数值的第几位上面
 * 先举几个例子模拟一下，注意下标+1 -1这些细节。
 */
class Solution {
public:
    int findNthDigit(int n) {
        if (n == 0) return 0;
        int digit = 1;  //当前是几位数
        long start = 1;  //1,10,100...
        long count = digit * 9 * start;     //digit位数区间的长度

        while (n > count) {
            n -= count;
            digit += 1;
            start *= 10;
            count = digit * 9 * start;
        }

        long num = start + (n - 1) / digit;         //题目给的n从0开始，而我们的逻辑中n从1开始
        int reminder = (n - 1) % digit;

        string s_num = to_string(num);
        return s_num[reminder] - '0';
    }
};
