/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 438-找到字符串中所有字母异位词.cpp
*   Author      : huihui571
*   Created date: 2020-11-22
*   Description : 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
说明：

    字母异位词指字母相同，但排列不同的字符串。
    不考虑答案输出的顺序。
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
 * 滑动窗口+排序比较。超时，应该是排序比较耗时，此外c++string没有高效的切片函数,得到窗口中的子串比较麻烦。
 */
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;

        int len = p.length();
        sort(p.begin(), p.end());

        int left = 0, right = 0;
        while (right < s.length())
        {
            right++;
            if ((right - left) == len)
            {
                string t(len, 0); 
                for (int j = 0; j < len; j++)
                {
                    t[j] = s[left + j];
                }
                cout << left << "  " << right << endl;
                cout << t << endl;
                sort(t.begin(), t.end());
                if (t == p)
                {
                    res.push_back(left);
                }
                left++;      
            } 
        }

        return res;
    }
};
#endif

#if 1
/**
 * 滑动窗口+将sort比较换成count字母出现次数比较
 * 
 */
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;

        int len = p.length();
        int mp[26] = {0};   //记录每个字符出现次数
        int ms[26] = {0}; 
        
        for (char c : p)
        {
            mp[c - 'a']++;
        }

        int left = 0, right = 0; //right指向窗口最后元素的下一个位置
        while (right < s.length()) 
        {
            right++;                    //扩大右边界
            ms[s[right - 1] - 'a']++;   //统计新加字母的出现次数
            if ((right - left) == len)
            {
                if (same(ms, mp))
                {
                    res.push_back(left);
                }
                ms[s[left] - 'a']--;    //移除左边字母出现次数
                left++;                 //缩小左边界
            } 
        }

        return res;
    }

    bool same(int m1[], int m2[])
    {
        for (int i = 0; i < 26; ++i)
        {
            if (m1[i] != m2[i])
                return false;
        }
        return true;
    }
};
#endif