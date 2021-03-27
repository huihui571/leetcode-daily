/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 125-验证回文串.cpp
*   Author      : huihui571
*   Created date: 2020-11-22
*   Description : 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。
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
 * 1. 双指针
 * 2. 逆序
 * 注意预处理：先过滤一遍字符串，把所有字母都转换成小写，其余字符抛弃。
 * c++几个内置函数：
 *     islower(char c) 是否为小写字母
 *     isupper(char c) 是否为大写字母
 *     isdigit(char c) 是否为数字
 *     isalpha(char c) 是否为字母
 *     isalnum(char c) 是否为字母或者数字
 *     toupper(char c) 字母小转大
 *     tolower(char c) 字母大转小
 */
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string t;
        for (char c : s)
        {
            if (isalnum(c))
                t += tolower(c);
        }
        int i = 0, j = t.length() - 1;

        while (i < j)
        {
            if (t[i] != t[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
};