/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 1736-替换隐藏数字得到的最晚时间.cpp 
*   Author      : huihui571
*   Created date: 2021-01-24
*   Description : 给你一个字符串 time ，格式为 hh:mm（小时：分钟），其中某几位数字被隐藏（用 ? 表示）。
*   有效的时间为 00:00 到 23:59 之间的所有时间，包括 00:00 和 23:59 。
*   替换 time 中隐藏的数字，返回你可以得到的最晚有效时间。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumTime(string time) {
        char h1 = time[0];
        char h2 = time[1];
        char m1 = time[3];
        char m2 = time[4];
        
        if (h1 == '?') {
            if (h2 <= '3' || h2 == '?')
                h1 = '2';
            else
                h1 = '1';
        }
        
        if (h2 == '?') {
            if (h1 == '2')
                h2 = '3';
            else
                h2 = '9';
        }
        
        if (m1 == '?') {
            m1 = '5';
        }
        
        if (m2 == '?') {
            m2 = '9';
        }
        
        string res;
        res.push_back(h1);
        res.push_back(h2);
        res.push_back(':');
        res.push_back(m1);
        res.push_back(m2);
        
        return res;
    }
};
