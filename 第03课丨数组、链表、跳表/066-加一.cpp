/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 066-加一.cpp
*   Author      : huihui571
*   Created date: 2020-07-15
*   Description : 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。
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

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int len = digits.size();
        for (int i = 0; i < len; ++i)
        {
            int sum = digits[len - 1 - i] + 1;      //进位，最开始加一也是这里
            digits[len - 1 - i] = sum % 10;
            if (sum < 10)
                return digits;              //个位小于9，加完直接返回
        }
        if (digits[0] == 0)   //说明最高为还需进位，1000000
        {
            digits.resize(digits.size() + 1, 0);
            digits[0] = 1; 
        }

        return digits;
    }
};