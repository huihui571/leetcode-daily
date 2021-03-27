/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 58-I-翻转单词顺序.cpp
*   Author      : huihui571
*   Created date: 2021-01-03
*   Description : 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
*   例如输入字符串"I am a student. "，则输出"student. a am I"。
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
#include <sstream>

using namespace std;

/**
 * 先去首尾空格
 * 1. 先整体反转，再逐个反转每个单词，可以用栈或者双指针。
 * 2. 单词存在顺序容器中(string)，再把每个单词添加到栈中，反转单词顺序。
 * 3. istringstream + 栈
 * 妙用stringstream去除空格。
 */
class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        stack<string> st;
        string str, res;

        while (ss >> str) {
            st.push(str);
            st.push(" ");
        }
        if (!st.empty())
            st.pop();   //多余空格

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};