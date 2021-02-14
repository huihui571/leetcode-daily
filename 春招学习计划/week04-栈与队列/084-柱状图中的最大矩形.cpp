/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 084-柱状图中的最大矩形.cpp 
*   Author      : huihui571
*   Created date: 2021-02-08
*   Description : 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
*   求在该柱状图中，能够勾勒出来的矩形的最大面积。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 枚举高度，然后向左向右找第一个比它小的柱子，可以用单调递增栈解决。
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        
        //前后补0
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        
        stack<int> st;
        for (int i = 0; i < heights.size(); i++) {/* code */
            //遇到比栈顶元素小的，开始弹出计算
            while (!st.empty() && heights[i] < heights[st.top()]) {     //注意栈里存的是下标
                int mid = st.top();
                st.pop();
                int left = st.top();    //栈中前一个元素就是它"左边第一个比它小的"
                int right = i;
                res = max(res, heights[mid] * (right - left - 1));
            }
            st.push(i);     //大于等于当前栈顶的则入栈
        }

        return res;
    }
};
