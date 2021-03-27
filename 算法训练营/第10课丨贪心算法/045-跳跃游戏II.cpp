/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 045-跳跃游戏II.cpp
*   Author      : huihui571
*   Created date: 2020-09-13
*   Description : 给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
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
 * 贪心法，每次跳选择能到达的最远位置来跳。
 */
class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int step = 0;
        int jump = 0;       //每次跳到的位置
        int max_reach = 0;  //记录最远可以到达的位置
        for (int i = 0; i < nums.size(); ++i)
        {
            if (max_reach >= i)
            {
                max_reach = max(max_reach, i + nums[i]); 
                if (i == jump)
                {
                    jump = max_reach;
                    step++;
                }
            }   
        }   
        return step;  
    }
};