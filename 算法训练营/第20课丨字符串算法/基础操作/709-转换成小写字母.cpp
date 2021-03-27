/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 709-转换成小写字母.cpp
*   Author      : huihui571
*   Created date: 2020-11-18
*   Description : 实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。
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
 * a-z：97-122  A-Z：65-90  0-9：48-57
 */
class Solution
{
public:
    string toLowerCase(string str)
    {
        for (char & ch : str)
        {
            if (ch >= 'A' && ch <= 'Z')
                ch += 32;
        }
        return str;
    }
};