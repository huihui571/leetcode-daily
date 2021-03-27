/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 641-设计循环双端队列.cpp
*   Author      : huihui571
*   Created date: 2020-07-26
*   Description : 设计实现双端队列。你的实现需要支持以下操作：

MyCircularDeque(k)：构造函数,双端队列的大小为k。
insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。
insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。
deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。
deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。
getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。
getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。
isEmpty()：检查双端队列是否为空。
isFull()：检查双端队列是否满了。

请不要使用内置的双端队列库。
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * 1.front = rear为空
 * 2.(rear + 1) % capacity == front 为满
 */
class MyCircularDeque {
private:
    vector<int> data;
    int capacity;   //K+1 留一个空位
    int front;      //指向队列头部第 1 个有效数据的位置
    int rear;       //指向队列尾部（即最后 1 个有效数据）的下一个位置

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        capacity = k + 1;   
        data.assign(capacity, 0);
        front = 0;
        rear = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;

        front = (front + capacity -1)  % capacity;  //加数组长度再-1，以免出现负数
        data[front] = value;

        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;

        data[rear] = value;
        rear = (rear + 1) % capacity;

        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;

        front = (front + 1) % capacity;

        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
       if (isEmpty()) return false;

        rear = (rear + capacity - 1) % capacity;

        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;

        return data[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
       if (isEmpty()) return -1;

        return data[(rear + capacity -1) % capacity];  //因为要取rear前一个元素，防止rear=0时越界 
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return front == rear;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        // 注意：这个设计是非常经典的做法
        return (rear + 1) % capacity == front;
    }
};


#if 0
/**
 * 622. 设计循环队列
 */
class MyCircularQueue {
private:

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {

    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {

    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {

    }
    
    /** Get the front item from the queue. */
    int Front() {

    }
    
    /** Get the last item from the queue. */
    int Rear() {

    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {

    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {

    }
};
#endif