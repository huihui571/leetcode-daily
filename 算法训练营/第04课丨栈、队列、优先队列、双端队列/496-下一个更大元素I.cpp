/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 496-下一个更大元素I.cpp
*   Author      : huihui571
*   Created date: 2020-07-25
*   Description : 给定两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。
nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。
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
 * 下一个更大/更小元素问题，典型单调栈应用。
 * 维护一个单调栈(递减)，对于当前元素(栈顶)，遍历后面的元素，若小于栈顶则先入栈存着;
 * 直到遇到大于栈顶的元素，则说明找到了一系列元素的目标，依次出栈
 */
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        stack<int> st;
        vector<int> res;
        unordered_map<int, int> mp;


        for (int i = 0; i < nums2.size(); ++i)
        {
            while (!st.empty() && nums2[i] > st.top())
            {
                mp[st.top()] = nums2[i];    //找到结果,nums2[i]就是栈顶元素的下一个更大元素
                st.pop();   
            }
            st.push(nums2[i]);
        }

        //栈中剩余的元素就是不存在下一个更大的
        while (!st.empty())
        {
            mp[st.top()] = -1;
            st.pop();
        }

        //在hash表中取出nums1指定元素的结果
        for (int i = 0; i < nums1.size(); ++i)
        {
            res.push_back(mp[nums1[i]]);
        }

        return res;
    }
};