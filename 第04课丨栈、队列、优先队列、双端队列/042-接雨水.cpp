/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 042-接雨水.cpp
*   Author      : huihui571
*   Created date: 2020-07-26
*   Description : 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）
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

/**
 * 1.单调栈
 * 对于栈顶这一列来说，其雨水的左边界是单调栈中前一个柱子，右边界是下一个更高的柱子，高度是左右边界中较小的减去当前柱子高度。
 * 转化为找下一个更大问题
 * 补充：本题中是单调递减栈(可以相等)。本题对于一个槽（不一定是一个柱子，因为这个方法一次求出一层或几层）来说，关键是要寻找
 * 它向左望去最高的柱子leftMax和向右望去最高的柱子rightMax。那么把比当前栈顶低的柱子理解为“左括号”入栈，把比栈顶高的理解
 * 为“右括号”出栈进行匹配。当找到右括号即rightMax时，便可以求出当前配对的leftMax之间的“一块”雨水。
 */
class Solution
{
public:
    int trap(vector<int>& height)
    {
        int res = 0;
        stack<int> st;

        for (int i = 0; i < height.size(); ++i)
        {
            while (!st.empty() && height[i] > height[st.top()])
            {
                int cur = st.top();
                st.pop();
                if (st.empty())     //栈空说明没有左边界(为-1)，面积为0，直接跳出不计算
                    break;
                int left = st.top();
                int right = i;

                int water_h = min(height[i], height[left]) - height[cur]; //左右柱子高度的min，减去height[cur]就是雨水的高度。
                res += water_h * (i - left - 1);                          //i - left - 1 是雨水的宽度。

            }
            st.push(i);
        }

        return res;
    }
};