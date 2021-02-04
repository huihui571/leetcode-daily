/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 003-无重复字符的最长子串.cpp 
*   Author      : huihui571
*   Created date: 2021-01-25
*   Description : 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#if 0 
/**
* 滑动窗口双指针
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int maxLen = 0;
        unordered_set<char> Set;

        while (right < s.length()) {
            while (Set.count(s[right])) {
                Set.erase(s[left++]);   //左侧弹出
            }
            Set.insert(s[right++]);
            maxLen = max(maxLen, right - left);
        }

        return maxLen;
    }
};
#else
/**
* 动态规划 
* dp[i]表示s[0..i]中最长无重复子串长度
* 若s[i]在之前有重复，重复位置为k，则dp[i] = i - k; 否则d[i] = dp[i - 1] + 1;
* 最后结果取max(dp)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        int n = s.length();
        vector<int> dp(n, 0);
        dp[0] = 1;
        unordered_map<char, int> dict;
        dict[s[0]] = 0;
        
        for (int i = 1; i < n; i++) {
            int j = dict.count(s[i]) ? dict[s[i]] : -1;
            dict[s[i]] = i;

            if (i - j > dp[i - 1]) {
                dp[i] = dp[i - 1] + 1;  //哈希表得到的位置是全局的，但如果j不在子串内部则无影响
            }
            else {
                dp[i] = i - j;
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
#endif
