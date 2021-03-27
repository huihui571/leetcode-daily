/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 049-字母异位词分组.cpp
*   Author      : huihui571
*   Created date: 2020-11-22
*   Description : 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
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
 * 构建哈希表，以每个单词排序后的字符串为key，原单词的集合为value。
 */
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> res;

        unordered_map<string, vector<string>> hash_map;

        for (string& s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            hash_map[t].push_back(s);
        }

        for (auto& m : hash_map)
        {
            res.push_back(m.second);
        }

        return res;
    }
};