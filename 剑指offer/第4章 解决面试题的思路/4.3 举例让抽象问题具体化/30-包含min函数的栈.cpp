/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 30-包含min函数的栈.cpp
*   Author      : huihui571
*   Created date: 2020-12-13
*   Description : 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
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
 * 辅助栈
 * min函数要求在栈每次push和pop之后都能保存当前最小值，所以想到用另一个辅助栈来保存每一个状态的最小值。
 */
class MinStack {
private:
    stack<int> data;
    stack<int> minData;
public:
    /** initialize your data structure here. */
    MinStack() {
        minData.push(INT32_MAX);
    }

    void push(int x) {
        data.push(x);
        if (x < minData.top())
            minData.push(x);
        else
            minData.push(minData.top());
    }

    void pop() {
        data.pop();
        minData.pop();
    }

    int top() {
        return data.top();
    }

    int min() {
        return minData.top();
    }
};
