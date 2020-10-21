/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 367-有效的完全平方数.cpp
*   Author      : huihui571
*   Created date: 2020-09-14
*   Description : 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
说明：不要使用任何内置的库函数，如  sqrt。
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

/**
 * 二分法
 * 若存在x * x = num，则num是完全平方数
 */
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num < 2)
            return true;

        long left = 2;
        long right = num / 2;

        while (left <= right)
        {
            long mid = left + (right - left) / 2;
            long long square = mid * mid;
            if (square == num)
            {
                return true;
            }
            else if (square < num)
            {
                left = mid + 1;
            }
            else if (square > num)
            {
                right = mid - 1;
            }
        }

        return false;
    }
};