/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : jz59-I-滑动窗口最大值.cpp
*   Author      : huihui571
*   Created date: 2021-02-13
*   Description : 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
*   返回滑动窗口中的最大值。
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
        return dq.front();
    }
    
    void push_back(int value) {
        data.push(value);

        while (!dq.empty() && value > dq.back()) {
            dq.pop_back();
        }
        dq.push_back(value);
    }
    
    int pop_front() {
        if (!dq.empty() && dq.front() == data.front()) {
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
