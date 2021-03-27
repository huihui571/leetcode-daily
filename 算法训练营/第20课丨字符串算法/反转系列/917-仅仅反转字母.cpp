/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 917-仅仅反转字母.cpp
*   Author      : huihui571
*   Created date: 2020-11-21
*   Description : 给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
*   示例 2：
    输入："a-bC-dEf-ghIj"
    输出："j-Ih-gfE-dCba"
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

class Solution
{
public:
    string reverseOnlyLetters(string S)
    {
        int i = 0, j = S.size() - 1;

        while (i < j)
        {
            while (i < j && !is_char(S[i])) i++;    //不是字母的就跳过，注意下标不要越界！
            while (i < j && !is_char(S[j])) j--;
            char t = S[i];
            S[i] = S[j];
            S[j] = t;
            i++;
            j--;
        }
        return S;
    }

    bool is_char(char c)
    {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }
};