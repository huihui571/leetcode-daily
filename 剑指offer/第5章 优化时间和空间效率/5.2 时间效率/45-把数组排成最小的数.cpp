/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 45-把数组排成最小的数.cpp
*   Author      : huihui571
*   Created date: 2020-12-29
*   Description : 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
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

/**
 * 重构比较
 * 技巧：1. lambda表达式 2. string的比较大小就是按字典序先比较第一个字符的大小再比较后面的字符
 */
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for (int num : nums) {
            strs.push_back(to_string(num));
        }

        sort(strs.begin(), strs.end(), [](string& s1, string& s2){return s1 + s2 < s2 + s1;});

        for (string str : strs) {
            res += str;
        }
        return res;
    }
};
