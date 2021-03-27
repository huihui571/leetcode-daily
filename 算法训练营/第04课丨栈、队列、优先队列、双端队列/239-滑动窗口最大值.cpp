/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 239-滑动窗口最大值.cpp
*   Author      : huihui571
*   Created date: 2020-07-26
*   Description : 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回滑动窗口中的最大值。
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <deque>
#include <algorithm>

using namespace std;

#if 1
//单调队列类实现
class MonoQueue
{
private:
    deque<int> data;
public:
    //从队尾push，把小于当前元素的都挤出去，直到碰到比自己大的或队列为空
    void push(int value)
    {
        while (!data.empty() && value > data.back())
        {
            data.pop_back();
        }
        data.push_back(value);
    }
    
    //获取队列中最大元素，队首就是最大
    int max()
    {
       return data.front();     
    }
    
    //从队头弹出值为value的元素，不等于front的元素说明之前被挤掉了，不需要pop了
    void pop(int value)
    {
        if (!data.empty() && value == data.front())
        {
            data.pop_front();
        }
    }

};
/**
 * 1.单调队列。
 * 滑动窗口问题，可以考虑双端队列deque。
 * 窗口向前滑动时，每一次入队(push_back)的元素把队内小于它的元素挤出去(pop_back)，
 * 这样保证队内元素单调递减，队首就是当前窗口最大值。
 */
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        MonoQueue window;
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i < k - 1)
            {
                window.push(nums[i]);   //先填满窗口的前k-1
            }
            else
            {
                window.push(nums[i]);           //填入第k个
                res.push_back(window.max());    //取出最大值
                window.pop(nums[i - k + 1]);    //弹出窗口尾巴
            }
        }

        return res;
    }
};
#endif