/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 003-无重复字符的最长字串.cpp 
*   Author      : huihui571
*   Created date: 2021-04-16
*   Description : 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 滑动窗口
 * 试探性右扩--如果不行，从左边弹出直到条件满足--右边进来--更新答案
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;

        unordered_map<char, int> freq;

        int left = 0, right = 0;

        while (right < s.length()) {
            if (freq.count(s[right])) {
                while (freq[s[right]]) {
                    freq.erase(s[left]);
                    left++;
                }
            }
            freq[s[right]]++;
            right++;

            res = max(res, right - left);
        }

        return res;
    }
};
