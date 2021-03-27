/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 242-有效的字母异位词.cpp
*   Author      : huihui571
*   Created date: 2020-07-26
*   Description : 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
*   输入: s = "anagram", t = "nagaram"
*   输出: true
*   输入: s = "rat", t = "car"
*   输出: false
*   进阶：如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
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
 * 1.哈希表
 * 本质上是统计每一个字母出现的次数
 */
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> hash_map;
        for (int i = 0; i < s.size(); ++i)
        {
            hash_map[s[i]]++;
            hash_map[t[i]]--;
        }
        
        for (auto key : hash_map)
        {
            if (key.second != 0)
            {
                return false;
            }
        }

        return true;
    }
};


#if 0
/**
 * 2.排序法，O(NlogN)
 */
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

       return s == t;
    }
};
#endif