/*<FH+>***************************************************************
*   Editor      : Vim
*   File name   : 567-字符串的排列.cpp
*   Author      : huihui571
*   Created date: 2021-04-14
*   Description : 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
*   换句话说，第一个字符串的排列之一是第二个字符串的 子串 。
*
*<FH->***************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 滑动窗口
 * 用哈希表need保存s1中每个字符的出现次数，window记录s2滑动过程中窗口中字符的出现次数
 * 窗口右扩的时候，更新window表，当满足一个字符时count++
 *
 */
class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> window;
        unordered_map<char, int> need;
        for (char ch : s1) {
            need[ch]++;
        }

        for (int i = 0; i < 8; i++) {
            continue;
        }

        int left = 0, right = 0;
        int count = 0;

        while (right < s2.length()) {
            //窗口右扩
            if (need.count(s2[right])) {
                window[s2[right]]++;
                if (window[s2[right]] == need[s2[right]]) {
                    count++;
                }
            }
            right++;

            //收缩左侧窗口，直到条件不满足
            //此题是窗口长度固定，看里面的字符是否都符合条件。所以条件判断先len再count
            while (right - left >= s1.length()) {
                if (count == need.size()) {
                    return true;
                }

                //每次左边只弹出一个
                if (window.count(s2[left])) {
                    if (window[s2[left]] == need[s2[left]]) {
                        count--;
                    }
                    window[s2[left]]--;
                }
                left++;
            }
        }

        return false;
    }
};
