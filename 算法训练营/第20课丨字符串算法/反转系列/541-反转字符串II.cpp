/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 541-反转字符串II.cpp
*   Author      : huihui571
*   Created date: 2020-11-21
*   Description : 给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。
    如果剩余字符少于 k 个，则将剩余字符全部反转。
    如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
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
 * 先实现反转子串，然后按条件判断
 */
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.length(); i += 2 * k)
        {
            if (i + 2 * k < s.length() || (i + 2 * k >= s.length() && i + k <= s.length()))
                reverse_substr(s, i, i + k - 1);
            // else if (i + k <= s.length())
            //     reverse_substr(s, i, i + k - 1);
            else if (i + k > s.length())
                reverse_substr(s, i, s.length() - 1);
        }

        return s;
    }

    //反转部分子串
    void reverse_substr(string& s, int start, int end)
    {
        cout << start << end << endl;
        while (start < end)
        {
            char t = s[start];
            s[start] = s[end];
            s[end] = t;
            start++;
            end--;
        }   
    }
};