/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 38-字符串的排列.cpp
*   Author      : huihui571
*   Created date: 2020-12-17
*   Description : 输入一个字符串，打印出该字符串中字符的所有排列。你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

#if 0
/**
 * 回溯法
 * 有重复数字，先排序让重复数字相邻
 */
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        string path;
        vector<bool> visited(s.length(), false);
        sort(s.begin(), s.end());
        backtrack(res, s, 0, path, visited);

        return res;
    }

    void backtrack(vector<string>& res, const string& s, int level, string& path, vector<bool>& visited) {
        if (level == s.length()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < s.length(); ++i) {
            if (visited[i])
                continue;
            if (i > 0 && s[i] == s[i - 1] && !visited[i - 1])   //i是重复的并且前面的i-1还没访问过,这是以i开头的一个分支,和i-1那个一样
                continue;
            cout << s[i] << endl;
            path.push_back(s[i]);        //做选择
            visited[i] = true;
            backtrack(res, s,  level + 1, path, visited);
            path.pop_back();            //撤销选择
            visited[i] = false;
        }
    }
};
#endif

#if 1
/**
 * 控制位置选择字符的思路，对于每一个位置，遍历当前的选择列表，这样不需要排序并且根据相邻的来判重
 * 用一个set来保证内循环的选择列表不出现重复字符就行。
 */
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        string path;
//        sort(s.begin(), s.end());
        backtrack(res, s, 0);

        return res;
    }

    //固定第i个字符
    //不需要path，因为是直接在s上进行操作，s就是path
    void backtrack(vector<string>& res, string& s, int i) {
        if (i == s.length() - 1) {
            res.push_back(s);
            return;
        }

        //选择列表是从第i个开始还没用过的字符
        unordered_set<char> set;
        for (int j = i; j < s.length(); ++j) {
            if (set.count(s[j]))
                continue;
            set.insert(s[j]);
            swap(s, i, j);      //将字符j固定到位置i上
            backtrack(res, s, i + 1);
            swap(s, i, j);
//            set.erase(s[j]); 这是内循环的set，只对当前for的选择列表去重，不是全局的，所以回溯时不需要撤销。用全局的应该也行。
        }
    }

    void swap(string& s, int i, int j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
};
#endif
