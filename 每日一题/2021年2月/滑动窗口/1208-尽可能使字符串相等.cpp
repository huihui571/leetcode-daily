/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 1208-尽可能使字符串相等.cpp 
*   Author      : huihui571
*   Created date: 2021-02-05
*   Description : 给你两个长度相同的字符串，s 和 t。
*   将 s 中的第 i 个字符变到 t 中的第 i 个字符需要 |s[i] - t[i]| 的开销（开销可能为 0），也就是两个字符的 ASCII 码值的差的绝对值。
*   用于变更字符串的最大预算是 maxCost。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。
*   如果你可以将 s 的子字符串转化为它在 t 中对应的子字符串，则返回可以转化的最大长度。
*   如果 s 中没有子字符串可以转化成 t 中对应的子字符串，则返回 0。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 滑动窗口/双指针
 */
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0;
        int len = s.length();
        int left = 0, right = 0;

        while (right < len) {
            int cost = abs(s[right] - t[right]);
            while (cost > maxCost) {
                maxCost += abs(s[left] - t[left]);
                left++;
            }
            maxCost -= cost;
            right++;
            res = max(res, right - left);
        }

        return res;
    }
};
