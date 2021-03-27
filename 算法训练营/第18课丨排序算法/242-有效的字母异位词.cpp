/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 242-有效的字母异位词.cpp
*   Author      : huihui571
*   Created date: 2020-11-05
*   Description : 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
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
 * 排序法
 */
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())       //长度不等直接返回false
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};
#endif

/**
 * 哈希表统计词频，每个字母出现频率一样就是字母异位词了。
 * 维护一个每个字母的计数器，遍历s计数器加1，遍历t计算器减1。如果在任何时候计数器低于零，说明该字母t中存在s中不存在。
 */
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())       //长度不等直接返回false
            return false;

        vector<int> table(26);
        for (char c : s)
        {
            table[c - 'a']++;
        }

        for (char c : t)
        {
            table[c - 'a']--;
            if (table[c - 'a'] < 0)
                return false;
        }

        return true;
    }
};