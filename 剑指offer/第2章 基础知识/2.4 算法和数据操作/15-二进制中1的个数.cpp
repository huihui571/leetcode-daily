/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 15-二进制中1的个数.cpp
*   Author      : huihui571
*   Created date: 2020-12-03
*   Description : 请实现一个函数，输入一个整数（以二进制串形式），输出该数二进制表示中 1 的个数。
*   例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。
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

#if 0
/**
 * 循环移位法
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            if (n & 0x01)
                count++;
            n >>= 1;
        }
        return count;    
    }
};
#endif

#if 1
/**
 * x & (x - 1)将x最低位的1置0
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n = n & (n - 1);
            count++
        }
        return count;    
    }
};
#endif