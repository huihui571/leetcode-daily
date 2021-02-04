/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 028-实现strStrKMP.cpp 
*   Author      : huihui571
*   Created date: 2021-01-27
*   Description : 实现 strStr() 函数。
*   给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 1. 暴力方法。从主串每个起点开始枚举和模式串一样长度的子串，看是否匹配。O(m*n)
 * 2. KMP算法。O(m+n)
 */
class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {// 注意i从1开始
            while (j >= 0 && s[i] != s[j + 1]) //前后缀不想同了
                j = next[j];    //向前回溯
            if (s[i] == s[j + 1])   //找到相同前后缀
                j++;
            next[i] = j;    //将j(前缀长度)赋给next[i]
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = -1; // // 因为next数组里记录的起始位置为-1
        for (int i = 0; i < haystack.size(); i++) { // 注意i就从0开始
            while(j >= 0 && haystack[i] != needle[j + 1]) { // 不匹配
                j = next[j]; // j 寻找之前匹配的位置
            }
            if (haystack[i] == needle[j + 1]) { // 匹配，j和i同时向后移动
                j++; // i的增加在for循环里
            }
            if (j == (needle.size() - 1) ) { // 文本串s里出现了模式串t
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

