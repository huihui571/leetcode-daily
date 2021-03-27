/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 017-电话号码的字母组合.cpp
*   Author      : huihui571
*   Created date: 2020-07-30
*   Description : 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
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
 * 回溯
 */
class Solution
{
private:
  unordered_map<char, string> letter_map;

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.empty())
            return res;
        
        int n = digits.length();
        string path;

        //构造哈希表映射 
        letter_map['2'] = "abc";
        letter_map['3'] = "def";
        letter_map['4'] = "ghi";
        letter_map['5'] = "jkl";
        letter_map['6'] = "mno";
        letter_map['7'] = "pqrs";
        letter_map['8'] = "tuv";
        letter_map['9'] = "wxyz";
        
        backtrack(res, path, digits, 0, n);

        return res;
    }

    void backtrack(vector<string>& res, string path, string digits, int start, int n)
    {
        if (path.size() == n)
        {
            res.push_back(path);
            return;
        }

        for (int i = start; i < digits.length(); i++)
        {
          string letters = letter_map[digits[i]];
          for (int j = 0; j < letters.size(); ++j) {
            path.push_back(letters[j]);
            backtrack(res, path, digits, i + 1, n);
            path.pop_back();
            }
    
        }
    }
};