/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 557-反转字符串中的单词III.cpp
*   Author      : huihui571
*   Created date: 2020-11-21
*   Description : 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
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
    string reverseWords(string s)
    {
        if (s.empty())
            return "";

        for (int start = 0; start < s.length(); ++start)
        {
            if (s[start] != ' ')
            {
                int end = start;
                while (end < s.length() && s[end] != ' ')
                {
                    end++;
                }
                    
                reverse_substr(s, start, end - 1);
                start = end;
            }
        }
        return s;
    }

    //反转部分子串
    void reverse_substr(string& s, int start, int end)
    {
        // cout << start << end << endl;
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