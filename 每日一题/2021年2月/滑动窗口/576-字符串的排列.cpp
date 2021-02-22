/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 576-字符串的排列.cpp 
*   Author      : huihui571
*   Created date: 2021-02-10
*   Description : 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
*   换句话说，第一个字符串的排列之一是第二个字符串的子串。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 滑动窗口。要记录s1和s2中对应字符的出现次数，这里用同一个数组++--，避免了遍历比较两个
 * freq数组。
 * 注意当窗口不符合条件的时候，需要收缩窗口至left++，这个过程中应该还原freq数组。
 */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int* freq = new int[26]();
        for (char ch : s1) {
            freq[ch - 'a']++;
        }
        int left = 0, right = 0;

        while (right < s2.length()) {
            if (freq[s2[right] - 'a']) {
                freq[s2[right] - 'a']--;
            }
            else {
                if (left < right) {
                    freq[s2[left] - 'a']++;
                    left++;
                    continue;
                }
                left++;
            }
            right++;

            if (right - left == s1.length()) {
                return true;
            }
        }

        return false;
    }
};
