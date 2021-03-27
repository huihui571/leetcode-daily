/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 50-第一个只出现一次的字符.cpp
*   Author      : huihui571
*   Created date: 2020-12-30
*   Description : 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
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
 * 哈希表记录出现次数
 */
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (char ch : s) {
            map[ch]++;
        }

        for (char ch : s) {
            if (map[ch] == 1)
                return ch;
        }
        return ' ';
    }
};