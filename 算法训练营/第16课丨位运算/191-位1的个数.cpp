/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 191-位1的个数.cpp
*   Author      : huihui571
*   Created date: 2020-11-01
*   Description : 编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。
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
#include <algorithm>

using namespace std;

#if 0
/**
 * 循环移位判断法
 */
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        for (int i = 0; i < 32; ++i)
        {
            if ((n & 1) == 1)
            {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
};
#endif

#if 1
/**
 * 二进制中，将n & n-1 可以使n最低位的1置0。
 * 我们不断地将最低位的1置0，直到没有1为止，此时n=0,操作的次数就是1的个数。
 */
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n != 0)
        {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};
#endif