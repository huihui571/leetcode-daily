/*<FH+>***************************************************************
*   Editor      : Vim
*   File name   : 076-最小覆盖字串.cpp
*   Author      : huihui571
*   Created date: 2021-04-08
*   Description : 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
*   注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
*
*<FH->***************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 字符串的滑动窗口问题往往需要一个freq数组/哈希表，记录目标中每个字符出现的频次，以便实现一些条件的判断。
 * 用两个freq数组分别记录s和t中目标字符出现的次数
 */
class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, len = INT_MAX;   //答案起始和长度

        unordered_map<char, int> window;    //窗口中的字符
        unordered_map<char, int> need;      //需要凑齐的字符
        for (char ch : t) {
            need[ch]++;
        }

        int left = 0, right = 0;
        int count = 0;              //窗口中符合条件的字符数量

        while (right < s.length()) {
            //窗口右扩
            if (need.count(s[right])) {
                window[s[right]]++;
                if (window[s[right]] == need[s[right]]) {
                    count++;
                }
            }
            right++;

            //收缩左窗口，直到条件不满足
            //此题是在存在这些字符的情况下，求窗口的最小尺寸。所以先条件判断count再len
            while (count == need.size()) {
                //更新答案
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }

                if (need.count(s[left])) {
                    if (window[s[left]] == need[s[left]]) {
                        count--;    //只在相等的时候减一次
                    }
                    window[s[left]]--;
                }
                left++;
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
