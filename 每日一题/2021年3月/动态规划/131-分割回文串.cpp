/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 131-分割回文串.cpp
*   Author      : huihui571
*   Created date: 2021-03-11
*   Description : 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
*   回文串 是正着读和反着读都一样的字符串。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 动态规划预处理 + DFS回溯
 */
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;

        int n = s.size();
//        vector<vector<bool>> dp(n, vector<bool>(n, true));  //一个字符肯定是回文，所以初始化为true
//        prepare(s, dp);
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            prepare2(s, i, i, dp);  //回文是奇数个: aba
            prepare2(s, i, i + 1, dp); //回文是偶数个：aa
        }
        backTrack(s, 0, res, path, dp);
        return res;
    }

    void backTrack(string& s, int start, vector<vector<string>>& res, vector<string>& path, vector<vector<bool>>& dp) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            //如果s[s:i]是回文
            if (dp[start][i]) {
                path.push_back(s.substr(start, i - start + 1));     //切出来
                backTrack(s, i + 1, res, path, dp);     //继续切s[i+1:]
                path.pop_back();
            }
        }
    }

    //双指针法判断s[start:i]是否是回文
    bool isPali(const string& s, int start, int end) {
        int i = start, j = end;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    //动态规划预处理，把s的所有子串是否是回文串先写到dp数组里
    void prepare(const string& s, vector<vector<bool>>& dp) {
        int n = s.length();
        //这里为什么要先遍历j呢？
        //因为动态规划处理回文也是从中心向两端扩展的，最外层的循环在枚举这个中心的起点，然后i的起点在j的左边一个，这样开始向两端扩散。
        //或者这里先遍历i但i从n-1开始，画出递推表格可以看出dp数组是由其左上角的元素转移而来，所以采用这样的遍历方向。
        for (int j = 1; j < n; ++j) {
            for (int i = j - 1; i >=0 ; --i) {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }
    }

    //中心扩展预处理
    void prepare2(const string& s, int left, int right, vector<vector<bool>>& dp) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            dp[left][right] = true;
            left--;
            right++;
        }
    }
};

