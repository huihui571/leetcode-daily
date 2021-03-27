/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 09-II用两个队列实现栈.cpp
*   Author      : huihui571
*   Created date: 2020-11-28
*   Description : 用两个队列来实现栈
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

class MyStack {
    queue<int> q;

public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        //将队列逆序，以便按照先进后出的顺序pop
        for (int i = 1; i < q.size(); ++i) {
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int front = q.front();
        q.pop();
        return front;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};