/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 41-数据流中的中位数.cpp
*   Author      : huihui571
*   Created date: 2020-12-25
*   Description : 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
设计一个支持以下两种操作的数据结构：
void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
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
 * 1. 插入不排序，O(1); quick selection求中位数，O(n)
 * 2. 插入用数组、链表排序，O(n); 求中位数arr[len/2]或定义指针指向中间节点，O(1)
 * 3. 插入用二叉搜索树、AVL排序，最好O(logn); 求中位数在子树中添加表示节点数目的字段，O(1)
 * 4. 左手一个大顶堆，右手一个小顶堆。插入O(logn)，求中位数O(1)
 * 我们没有必要把所有数据进行排序。只需要保证数据左半边的数都小于右半边的数，那么根据左半边的数的最大值及右半边的数的最小值即可得到中位数
 */
class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    //始终保持大顶堆的堆顶元素小于小顶堆的堆顶元素，并且两个堆的size之差不超过1
    void addNum(int num) {
        if (maxHeap.size() == minHeap.size()) {
            maxHeap.push(num);
            int tmp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(tmp);
        }
        else {
            minHeap.push(num);
            int tmp = minHeap.top();
            minHeap.pop();
            maxHeap.push(tmp);
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;   //NOTE:这里除2.0否则返回是截断的整型而不是浮点型
        }
        else {
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
