/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 084-柱状图中最大的矩形.cpp
*   Author      : huihui571
*   Created date: 2020-07-20
*   Description : 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。
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
#include <algorithm>

using namespace std;


#if 1
/**
 * 2.单调栈
 * 对于每一个柱子，计算以它为高的最大矩形面积，所以去求当前柱子的左右边界，即找左边和右边第一个小于自己的柱子。
 */
class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int res = 0;

        //前后补0便于处理
        heights.insert(heights.begin(), 0);     //如果前面不插0，则pop出cur柱子后栈可能为空，导致无法确定其左边界(其实此时左边界就是-1)。
        heights.push_back(0);               //如果后面不插0，则最后栈中可能剩下几个元素(没有比它们更小的)。这里加0可以强制排空。

        stack<int> st;
        for (int i = 0; i < heights.size(); ++i)
        {
            while (!st.empty() && heights[i] < heights[st.top()])   //找到下一个更矮矩形
            {
                // 对栈中柱体来说，栈中的前一个柱体就是其「左边第一个小于自身的柱体」；
                // 若当前柱体 i 的高度小于栈顶柱体的高度，说明 i 是栈顶柱体的「右边第一个小于栈顶柱体的柱体」。
                // 因此以栈顶柱体为高的矩形的左右宽度边界就确定了，可以计算面积 ～
                int cur = st.top();  
                st.pop();       //NOTE:由于栈中元素不一定连续，所以这里要pop找栈中上一个元素，而不是cur-1
                int left = st.top();   
                int right = i;       
                res = max(res, heights[cur] * (right - left - 1)); 
                  
            }
            st.push(i);
        }

        return res;
    }
};
#endif

#if 0
/**
 * 2.单调栈
 * 官方题解
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n, n);
        
        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                right[mono_stack.top()] = i;
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};
#endif


#if 0
/**
 * 1.暴力方法，就是固定一个变量，枚举另一个变量。
 * a.枚举宽，需要分别枚举左右边界，固定边界后，计算高即为当前包含最短柱子的高度。
 */
class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        int res = 0;

        for (int left = 0; left < n; ++left)    //枚举左边界
        {
            int min_height = INT_MAX;
            for (int right = left; right < n; ++right)      //枚举右边界
            {
                min_height = min(min_height, heights[right]);       //确定高度
                res = max(res, (right - left + 1) * min_height);        //计算面积
            }
        }

        return res;
    }
};
#endif

#if 0
/**
 * 1.暴力方法，就是固定一个变量，枚举另一个变量。
 * b.枚举高，以当前柱子为中心，向左右分别找到第一个比当前矮的柱子，即为左右边界。
 */
class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        int res = 0;

        for (int mid = 0; mid < n; ++mid)
        {
            int height = heights[mid];  //枚举高
            int left = mid;
            int right = mid;
            //确定左右边界
            while (left - 1 >= 0 && heights[left - 1] > height)
            {
                left--;
            }
            while (right + 1 < n && heights[right + 1] > height)
            {
                right++;
            }
            //计算面积
            res = max(res, (right - left + 1) * height);
        }

        return res;
    }
};
#endif

