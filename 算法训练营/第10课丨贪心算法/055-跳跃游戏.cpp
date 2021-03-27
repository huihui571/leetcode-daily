/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 055-跳跃游戏.cpp
*   Author      : huihui571
*   Created date: 2020-09-13
*   Description : 给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。
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
 * 贪心法。
 * 如何判断是否可达？如果位置x是可以到达的，那么若位置y满足x + nums[x] >= y，则y也可以到达。
 * 维护一个变量保存最远可以到达的位置。如果当前位置在最远可以到达的位置的范围内，则更新最远可以到达的位置。
 */
class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int max_reach = 0;  //记录最远可以到达的位置
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > max_reach)  //当前位置不在可以到达范围内，返回false
                return false;
            max_reach = max(max_reach, i + nums[i]);    //更新最远可以到达的位置
        }
        return true;
    }
};
#if 0
/**
 * 贪心法，从后往前，看最早可以起步的地方而不是最远能到达的地方。
 */
class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int start = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            if (i + nums[i] >= start)   //从位置i起步可以到达start
                start = i;          //更新start,向前推
        }   
        return start == 0;  //是否可以从0起步
    }
};
#endif