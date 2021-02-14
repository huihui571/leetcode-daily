/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 224-基本计算器.cpp 
*   Author      : huihui571
*   Created date: 2021-02-10
*   Description : 实现一个基本的计算器来计算一个简单的字符串表达式 s 的值。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 只有加减和括号没有乘除，可以先不用考虑运算符优先级，需要处理3个部分：
 * 1. 运算数是十位以上数字--num*10+
 * 2. 正号和负号--sign标志
 * 3. 括号带来的运算顺序改变--栈
 */
class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int sign = 1;
        stack<int> st;

        for (int i = 0; i < s.length(); i++) {
            int num = 0;
            if (s[i] >= '0') {
                while (i < s.length() && s[i] >= '0') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;    //循环多加了一步，退回
                res += sign * num;
            }
            else if (s[i] == '+') {
                sign = 1;
            }
            else if (s[i] == '-') {
                sign = -1;
            }
            else if (s[i] == '(') {
                st.push(res);       //将当前的操作数和负号入栈，res和sign复位，先计算括号里面的
                st.push(sign);
                res = 0;
                sign = 1;
            }
            else if (s[i] == ')') {
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            }
        }
        
        return res;
    }
};
