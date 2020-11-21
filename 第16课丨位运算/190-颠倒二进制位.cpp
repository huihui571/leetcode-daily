/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 190-颠倒二进制位.cpp
*   Author      : huihui571
*   Created date: 2020-11-01
*   Description : 颠倒给定的 32 位无符号整数的二进制位。
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
 * 每次取n最低位，赋给res，然后n右移一位，res左移一位。
 */
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 0;
        for (int i = 0; i < 31; ++i)
        {
            res += (n & 0x01);
            n = n >> 1;
            res = res << 1;
        }
        res += n;   //加上最后一位
        return res;
    }
};