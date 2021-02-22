/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : jz38-字符串的排列.cpp 
*   Author      : huihui571
*   Created date: 2021-02-17
*   Description : 输入一个字符串，打印出该字符串中字符的所有排列。
*   你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        string path;
        unordered_set<char> Set;
        backTrack(s, 0, path, res, Set);
        return res;
    }

    void backTrack(string& s, int level, string& path, vector<string>& res, unordered_set<char>& Set) {
        if (path.length() == s.length()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            if (Set.count(s[i]))
                return;
            path.push_back(s[i]);
            Set.insert(s[i]);
            backTrack(s, level + 1, path, res, Set);
            path.pop_back();
            Set.erase(s[i]);
        }
    }
};
