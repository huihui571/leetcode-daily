/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 5677-统计同构子字符串的数目.cpp 
*   Author      : huihui571
*   Created date: 2021-02-14
*   Description : 给你一个字符串 s ，返回 s 中 同构子字符串 的数目。由于答案可能很大，只需返回对 109 + 7 取余 后的结果。
*   同构字符串 的定义为：如果一个字符串中的所有字符都相同，那么该字符串就是同构字符串。
*   子字符串 是字符串中的一个连续字符序列。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 滑动窗口
 */
class Solution {
public:
    int countHomogenous(string s) {
        int res = 0;
        unordered_map<string, int> count;
        int left = 0, right = 0;

        while (right < s.length()) {
            if (s[right] != s[left]) {
                left = right;
            }
            else {
                // string str = "";
                // for(int i = left; i <= right; i++) {
                //     str.push_back(s[i]);
                //     count[str] = (count[str] + 1) % 1000000007;
                // }
                res = (res + right - left + 1)  % 1000000007;    //只求总的数量其实不用计算具体的字符串次数
                right++;     
            }

        }

        // for (auto it = count.begin(); it != count.end(); it++) {
        //     res += it->second;
        //     // printf("%s : %d\n", it->first.c_str(), it->second);
        // }
        return res;
    }
};

