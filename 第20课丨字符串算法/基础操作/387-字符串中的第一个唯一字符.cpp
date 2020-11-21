/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 387-字符串中的第一个唯一字符.cpp
*   Author      : huihui571
*   Created date: 2020-11-18
*   Description : 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1
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
 * 1. 暴力
 * 2. 哈希表
 */
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int res = -1;

        unordered_map<char, int> hash_map;
        for (char ch : s)
        {
            hash_map[ch]++;
        }

        for (int i = 0; i < s.length(); ++i)
        {
            if (hash_map[s[i]] == 1)
            {
                res = i;
                break;
            }
        }
        
        return res;
    }
};