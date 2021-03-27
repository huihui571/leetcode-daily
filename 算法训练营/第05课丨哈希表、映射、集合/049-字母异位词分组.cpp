/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 049-字母异位词分组.cpp
*   Author      : huihui571
*   Created date: 2020-07-27
*   Description : 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
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
#include <algorithm>

using namespace std;

/**
 * 哈希表。把每一个字符串排序后的结果作为key。
 */
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash_map;

        for (int i = 0; i < strs.size(); ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            hash_map[s].push_back(strs[i]);     //s为排序后的单词，作为key;异构词的vector作为value
        }

        for (auto& m : hash_map)
        {
            res.push_back(m.second);
        }
        return res;
    }
};