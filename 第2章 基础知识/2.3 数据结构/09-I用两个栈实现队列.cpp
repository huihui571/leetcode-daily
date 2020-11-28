/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 09-I用两个栈实现队列.cpp
*   Author      : huihui571
*   Created date: 2020-11-27
*   Description : 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
*   分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
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

#if 0
/**
 * 每次插入的时候，要把当前元素插到栈底，这样弹出的顺序就是先进先出了。
 * 那就得把栈里之前的元素倒出来，再倒回去，这可以借助另一个栈来实现。
 * 插入O(n),删除O(1)
 */
class CQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    CQueue() {
        while (!s1.empty()) {
            s1.pop();
        }
        while (!s2.empty()) {
            s2.pop();
        }  
    }
    
    void appendTail(int value) {
        //把s1中的元素全部移到s2中
        while (!s1.empty()) {
            int tmp = s1.top();
            s1.pop();
            s2.push(tmp);
        }
        //插入元素
        s1.push(value);
        //s2移回s1
        while (!s2.empty()) {
            int tmp = s2.top();
            s2.pop();
            s1.push(tmp);
        }
    }
    
    int deleteHead() {
        if (s1.empty())
            return -1;
        int head = s1.top();
        s1.pop();
        return head;
    }
};
#endif

#if 1
/**
 * 两个栈，一个负责插入，一个负责删除，相当于队列的两个头
 * 插入正常往s1里插，删除时由于要删除的元素在栈底，所以把元素全部移到s2里，要删除的就在栈顶了
 * 插入O(1),删除O(1)
 */
class CQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    CQueue() {
        while (!s1.empty()) {
            s1.pop();
        }
        while (!s2.empty()) {
            s2.pop();
        }  
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if (s2.empty()) {
            if (s1.empty())
                return -1;
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int head = s2.top();
        s2.pop();
        return head;
    }
};
#endif
/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */