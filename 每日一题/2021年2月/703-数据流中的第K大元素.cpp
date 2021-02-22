/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 703-数据流中的第K大元素.cpp 
*   Author      : huihui571
*   Created date: 2021-02-11
*   Description : 设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。
*   请实现 KthLargest 类：
*       KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
*       int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 堆（优先队列）
 */
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++){
            heap.push(nums[i]);
            if (heap.size() > k)
                heap.pop();
        }
    }
    
    int add(int val) {
        heap.push(val);
        if (heap.size() > this->k)
            heap.pop();
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
