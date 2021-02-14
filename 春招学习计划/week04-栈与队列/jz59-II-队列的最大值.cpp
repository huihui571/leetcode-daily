/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : jz59-II-队列的最大值.cpp 
*   Author      : huihui571
*   Created date: 2021-02-14
*   Description : 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
*   若队列为空，pop_front 和 max_value 需要返回 -1
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 关键是如何在O(1)时间内求得队列最大值，考虑到以空间换时间，由于有弹出操作因此用一个变量记录最大值是不行的。
 * 参考滑动窗口中的最大值，这个队列在插入和弹出的过程中，就和滑动窗口是一样的。因此可以用单调队列来求最大值。
 */
class MaxQueue {
private:
    queue<int> data;
    deque<int> dq;
public:
    MaxQueue() {
    }
    
    int max_value() {
        return dq.empty() ? -1 : dq.front();
    }
    
    void push_back(int value) {
        data.push(value);

        while (!dq.empty() && value > dq.back()) {
            dq.pop_back();
        }
        dq.push_back(value);
    }
    
    int pop_front() {
        if (data.empty()) {
            return -1;
        }

        if (dq.front() == data.front()) {
            dq.pop_front();
        }

        int front = data.front();
        data.pop();
        return front;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
