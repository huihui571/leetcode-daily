/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 31-栈的压入、弹出序列.cpp
*   Author      : huihui571
*   Created date: 2020-12-13
*   Description : 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
*   例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。
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

using namespace std;

/**
 * 用一个栈来模拟一下popped的顺序，如果能顺利模拟就ok
 * 将pushed中每个数依次入栈，同时判断栈顶是不是popped中下一个要pop的值，如果是就马上pop，如果不是就继续push。
 */
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;

        int i = 0;
        for (int val : pushed) {
            st.push(val);       //pushed中元素依次压栈
            while (!st.empty() && st.top() == popped[i]) {  //如果栈顶元素等于popped当前元素，就尝试出栈
                st.pop();
                i++;            //尝试popped中下一个元素
            }
        }

        return st.empty();
    }
};