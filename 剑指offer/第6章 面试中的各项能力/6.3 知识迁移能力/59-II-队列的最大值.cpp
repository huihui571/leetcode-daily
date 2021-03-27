/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 59-II-队列的最大值.cpp
*   Author      : huihui571
*   Created date: 2021-01-04
*   Description : 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
* 若队列为空，pop_front 和 max_value需要返回 -1
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
 * 单调队列来保存最大值，另外一个辅助队列记录所有元素(维护单调队列过程中会丢弃一些元素)
 */
class MaxQueue {
private:
    deque<int> data;    //单调递减
    queue<int> q;       //辅助队列，记录所有插入的元素
public:
    MaxQueue() {

    }

    int max_value() {
        if (data.empty())
            return -1;
        return data.front();
    }

    void push_back(int value) {
        while (!data.empty() && value > data.back())    //把前面比value小的元素都挤出去
            data.pop_back();
        data.push_back(value);                          //value入队
        q.push(value);
    }

    int pop_front() {
        if (q.empty())
            return -1;
        int front = q.front();
        q.pop();
        if (front == data.front())      //如果data的front是这个值，那就弹出；如果不是，那说明这个值不在里面，就不用管了
            data.pop_front();

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