/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 59-I-滑动窗口的最大值.cpp
*   Author      : huihui571
*   Created date: 2021-01-04
*   Description : 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
*   输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
*   输出: [3,3,5,5,6,7]
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
 * 单调队列。动态维护一个双端队列，让队列头部(front)始终是当前滑动窗口的最大值的索引。
 * 只需要在尾部push的时候，把前面小于自己的元素都挤出去，这样就能保证队列是单调递减的。由于在头部和尾部都需要弹出元素，所以这里选择双端队列。
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty() || k == 0) return res;
        deque<int> dq;
        
        //前k个元素，此时窗口还未满
        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && nums[i] > dq.back())
                dq.pop_back();
            dq.push_back(nums[i]);
        }
        res.push_back(dq.front());              //第一个最大值

        //后续元素
        for (int i = k; i < nums.size(); ++i) {
            if (dq.front() == nums[i - k])      //最大值如果是窗口左侧第一个元素，那么右移时要丢弃它
                dq.pop_front();

            while (!dq.empty() && nums[i] > dq.back())
                dq.pop_back();
            dq.push_back(nums[i]);

            res.push_back(dq.front());          //保存最大值
        }

        return res;
    }
};
