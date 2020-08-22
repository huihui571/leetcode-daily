/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 155-最小栈.cpp
*   Author      : huihui571
*   Created date: 2020-07-16
*   Description : 
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <stack>
#include <limits.h>
#include <algorithm>
#include <utility>
// #include <bits/stdc++.h>

using namespace std;

/**
 * 用一个辅助栈，栈顶保存当前为止主栈中最小元素
 */
#if 0
class MinStack
{
    stack<int> s1;
    stack<int> s_min;   //辅助栈

public:
    MinStack()
    {
        s_min.push(INT_MAX);    //求最小，先初始化为最大
    }

    void push(int x)
    {
        s1.push(x);
        s_min.push(min(x, s_min.top()));
        // if (x < s_min.top()){
        //     s_min.push(x);
        // }
    }

    void pop()
    {
        s1.pop();
        s_min.pop();    //二栈同步，大小相同
    }

    int top()
    {
        return s1.top();
    }

    int getMin()
    {
        return s_min.top();
    }

    ~MinStack();
    
};
#endif

/**
 * 用pair来成对保存主栈元素和当前元素对应的最小值，这样只用一个栈，但空间复杂度是一样的。
 */
class MinStack
{
    stack<pair<int, int> > s;
    pair<int, int> p;
public:
    MinStack()
    {
        p.second = INT_MAX;
        s.push(p);
    }

    void push(int x)
    {     
        int min_x = s.top().second;
        p.first = x;
        p.second = min(x, min_x);
        s.push(p);
    }

    void pop()
    {
        s.pop();
    }

    int top()
    {
        return s.top().first;
    }

    int getMin()
    {
        return s.top().second;
    }

    
};