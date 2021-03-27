/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 05-替换空格.cpp
*   Author      : huihui571
*   Created date: 2020-11-23
*   Description : 请实现一个函数，把字符串 s 中的每个空格替换成"%20"
*   示例 1：
    输入：s = "We are happy."
    输出："We%20are%20happy."
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

#if 0
/**
 * 由于原来空格的一个字符被替换为%20三个字符，所以替换后为避免覆盖后面的字符要依次后移，时间复杂度O(n2)
 * 参考283-移动零那题的思路，先遍历字符串统计空格的个数，然后直接在结果串中留出足够的空间，避免移动操作
 * 时间复杂度O(n)
 */
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        for (char ch : s) {
            if (ch == ' ')
                count++;
        }
        string res = "";
        for (char ch : s) {
            if (ch != ' ')
                res += ch;
            else
                res += "%20";
        }

        return res;
    }
};
#endif

#if 1
/**
 * 如果要求原地替换呢？
 * 在原数组上操作，为了不移动，应该从后往前进行替换，因为后面的空间是空着的。
 */
class Solution {
public:
    string replaceSpace(string s) {
        int len = s.length();
        int count = 0;
        for (char ch : s) {
            if (ch == ' ')
                count++;
        }

        s.resize(len + count * 2);
        int j = s.length() - 1;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] != ' ')
            {
                s[j] = s[i];
                j--;
            }
            else
            {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 3;
            }
        }

        return s;
    }
};
#endif