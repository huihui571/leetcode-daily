/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 438-找到字符串中所有的字母异位词.cpp 
*   Author      : huihui571
*   Created date: 2021-04-16
*   Description : 给定一个字符串?s?和一个非空字符串?p，找到?s?中所有是?p?的字母异位词的子串，返回这些子串的起始索引。
*   字符串只包含小写英文字母，并且字符串?s?和 p?的长度都不超过 20100。
*   说明：
*   字母异位词指字母相同，但排列不同的字符串。
*   不考虑答案输出的顺序。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 字母异位词就是s中找一个窗口，其中每个字符的出现次数和p都相同
 * 滑动窗口法
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        unordered_map<char, int> window;
        unordered_map<char, int> need;
        for (char ch : p) {
            need[ch]++;
        }

        int left = 0, right = 0;
        int count = 0;
        
        while (right < s.length()) {
            if (need.count(s[right])) {
                window[s[right]]++;
                if (window[s[right]] == need[s[right]]) {
                    count++;
                }
            }
            right++;

            while (right - left >= p.length()) {
                if (count == need.size()) {
                    res.push_back(left);
                }

                if (window.count(s[left])) {
                    if (window[s[left]] == need[s[left]]) {
                        count--;
                    }
                    window[s[left]]--;
                }
                left++;
            }
        }
        
        return res;
    }
};
