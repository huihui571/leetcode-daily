/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 344-反转字符串.cpp
*   Author      : huihui571
*   Created date: 2020-11-21
*   Description : 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
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
 * 不能额外分配空间，那只能双指针了
 */
class Solution
{
public:
    void reverseString(vector<char>& s)
    {
        int i = 0, j = s.size() - 1;

        while (i < j)
        {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
            i++;
            j--;
        }

    }
};