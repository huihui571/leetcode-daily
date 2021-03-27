/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 020-有效的括号.cpp
*   Author      : huihui571
*   Created date: 2020-07-16
*   Description : 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

bool isValid(string s)
{
    if (s.empty()) return true;     //初始字符串为空
    stack <char, vector<char> > st;
    // stack<char> st;
    for (int i = 0; i < s.size(); ++i){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        } 
        else {
            if (st.empty()) return false;       //左右数量不对称，右>左
            char left = st.top();
            st.pop();
            if ((left == '(' && s[i] == ')') || (left == '[' && s[i] == ']') || (left == '{' && s[i] == '}')) {
                continue;
            }
            else {
                return false;
            }     
        }
    }
    return st.empty();

}