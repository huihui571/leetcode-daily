/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 231-2的幂.cpp
*   Author      : huihui571
*   Created date: 2020-11-01
*   Description : 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
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
 * 2的幂的依据实际上就是二进制只有一个1，其余全是0
 * 可以循环统计1的个数，时间复杂度O(N)
 */
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        //负数一定不是
        if (n < 0)
            return false;
        //负数最高位是1，但是负数情况前面已经排除
        int count = 0;
        for (int i = 0; i < 32; ++i)
        {
            if ((n & 1) != 0)
                count++;
            n = n >> 1;
        }
        return count == 1 ? true : false;
    }
};
#endif

#if 1
/**
 * 除二取余法，如果是2的幂，那么除的过程中余数应该一直是0，直到最后只剩一个商==1
 * 时间复杂度O(logN)
 */
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        while (n % 2 == 0)
        {
            n = n / 2;
        }
        return n == 1;
    }
};
#endif

#if 0
/**
 * n & (-n) 可以将除最低位的1之外其它位置0
 * O(1)
 */
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        return (n & (-n)) == n; //n == -2^32时，-n会溢出
    }
};
#endif

#if 0
/**
 * n & (n - 1) 可以将最低位的1置0
 * O(1)
 */
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        return (n & (n - 1)) == 0;
    }
};
#endif