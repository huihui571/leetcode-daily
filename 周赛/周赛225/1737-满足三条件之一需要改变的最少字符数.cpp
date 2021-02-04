/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 1737-满足三条件之一需要改变的最少字符数.cpp 
*   Author      : huihui571
*   Created date: 2021-01-28
*   Description : 给你两个字符串 a 和 b ，二者均由小写字母组成。一步操作中，你可以将 a 或 b 中的 任一字符 改变为 任一小写字母 。
*   操作的最终目标是满足下列三个条件 之一 ：
*       a 中的 每个字母 在字母表中 严格小于 b 中的 每个字母 。
*       b 中的 每个字母 在字母表中 严格小于 a 中的 每个字母 。
*       a 和 b 都 由 同一个 字母组成。
*   返回达成目标所需的 最少 操作数。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 审题没审好。是a中"每个字母"严格小于b中"每个字母"，不是每个对应位置的字母。ab由同一个字母组成也是指ab的所有字母都是这个字母。
 * 因此只要找到一个分界线字目c，让将a中大于等于的字母c的调整，b中小于等于c的字母调整即可。
 * 这个分界线字母c可以在26个字母中枚举。
 * 三个条件分开考虑，最后取次数最少的那个。
 */
class Solution {
public:
    int minCharacters(string a, string b) {
        int m = a.length(), n = b.length();
        vector<int> va(26), vb(26);
        //先统计a，b中每个字母出现的次数
        for (char c : a) {
            va[c - 'a']++;
        }
        for (char c : b) {
            vb[c - 'a']++;
        }

        int res = m + n;

        //第三个条件
        for (int i = 0; i < 26; i++) {
            res = min(res, m - va[i] + n - vb[i]);  //如果以字母i为分界，那么要修改的次数是a中不是i的字符数量+b中不是i字符的数量
        }

        //第一个条件和第二个条件是对偶的
        auto make_smaller = [&](vector<int>& a, vector<int>& b) {
            for (int i = 1; i < 26; i++) {
                int cur = 0;
                for (int j = i; j < 26; j++) {
                    cur += a[j];
                }
                for (int j = 0; j < i; j++) {
                    cur += b[j];
                }
                res = min(res, cur);
            }
        };

        make_smaller(va, vb);
        make_smaller(vb, va);
        
        return res;
    }
};
