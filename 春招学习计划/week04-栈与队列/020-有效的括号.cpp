/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 020-有效的括号.cpp 
*   Author      : huihui571
*   Created date: 2021-02-11
*   Description : 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
*   有效字符串需满足：
*       左括号必须用相同类型的右括号闭合。
*       左括号必须以正确的顺序闭合。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            else {
                if (!st.empty() && isMatch(st.top(), ch)) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }

    bool isMatch(char c1, char c2) {
        // cout << c1 << ", " << c2 << endl;
        if (c1 == '(') {
            return c2 == ')';
        }
        else if (c1 == '[') {
            return c2 == ']';
        }
        else if (c1 == '{') {
            return c2 == '}';
        }
        return false;
    }
};
