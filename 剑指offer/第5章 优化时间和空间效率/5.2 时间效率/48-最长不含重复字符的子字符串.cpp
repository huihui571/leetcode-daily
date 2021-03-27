/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 48-最长不含重复字符的子字符串.cpp
*   Author      : huihui571
*   Created date: 2020-12-30
*   Description : 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
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

#if 0
/**
 * 滑动窗口，双指针
 * 哈希set来判重
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        int res = -1;
        int left= 0, right = 0;
        unordered_set<char> set;

        while (right < s.length()) {
            if (set.count(s[right])) {
                while (set.count(s[right])) { //遇到重复字符，弹出窗口左侧元素，直到不重复
                    set.erase(s[left++]);
                }
            }
            set.insert(s[right++]);     //添加进窗口
            res = max(res, right - left);
        }

        return res;
    }
};
#endif

#if 1
/**
 * 动态规划
 * dp[i]表示以s[i]结尾的最长不重复字串长度，最后结果取max(dp)
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        int n = s.length();
        unordered_map<char, int> dict;
//        dict[s[0]] = 0;
//        vector<int> dp(n);
//        dp[0] = 1;
//
//        for (int i = 1; i < n; ++i) {
//            int j = -1;
//            if (dict.count(s[i])) {
//                j = dict[s[i]];     //获取当前重复字符上一次出现的位置
//            }
//            dict[s[i]] = i;    //更新位置
//            if (i - j > dp[i - 1])
//                dp[i] = dp[i - 1] + 1;  //j不在子串内部，不影响
//            else
//                dp[i] = i - j;          //j在子串内部，则字串起点改为j+1，长度为i-j
//        }
//
//        return *max_element(dp.begin(), dp.end());
        int res = 0, tmp = 0;
        for (int i = 0; i < n; ++i) {
            int j = dict.count(s[i]) ? dict[s[i]] : -1;
            dict[s[i]] = i;
            tmp = i - j > tmp ? tmp + 1 : i - j;
            res = max(res, tmp);
        }
        return res;
    }
};
#endif