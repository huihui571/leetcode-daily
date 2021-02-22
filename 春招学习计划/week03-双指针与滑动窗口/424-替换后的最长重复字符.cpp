/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 424-替换后的最长重复字符.cpp 
*   Author      : huihui571
*   Created date: 2021-02-05
*   Description : 给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。
*   在执行上述操作后，找到包含重复字母的最长子串的长度。
*   注意：字符串长度 和 k 不会超过 104。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 滑动窗口。
 * 这题只求最大长度而不求区间，所以right - left维护最大长度即可。如果加进来的值符合条件，那么right右移。
 * 如果当前窗口长度 > 出现次数最多字符的次数 + k，即右窗口加进来的值是不符合条件的，那么左右一起滑动。
 * 在这个过程中窗口长度是非递减的。
 */
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;    
        int* freq = new int[26]();
        int maxCount = 0;  //出现次数最多的字符出现的次数，只有这个值被更新的时候，窗口长度才需要扩大，否则就是左右一起滑动保持之前的值。
        while (right < s.length()) {
            freq[s[right] - 'A']++;     //更新每个字符的出现次数
            maxCount = max(maxCount, freq[s[right] - 'A']);
            if (right - left + 1 > maxCount + k) {
                freq[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right - left;
    }
};
