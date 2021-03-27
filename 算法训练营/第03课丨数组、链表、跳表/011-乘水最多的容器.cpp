/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 011-乘水最多的容器.cpp
*   Author      : huihui571
*   Created date: 2020-07-01
*   Description : 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
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
 * 双指针搜索问题，即找到合适的柱子(数值)
 * 从两侧开始，因为两侧底边最长。然后向中间搜索，每次换掉较短的那根柱子。
 */
class Solution
{
public:
    int maxArea(vector<int> height)
    {
        int i = 0;
        int j = height.size() - 1;
        int max_area = 0;
        while (i < j)
        {
            max_area = max(max_area, get_area(height, i, j));   //更新最大值
            if (height[i] <= height[j])                         //选较短的那跟换掉
            {
                i++;
            }
            else
            {
                j--;
            }
        }
    
        return max_area;
    }
    //计算面积
    int get_area(vector<int>& height, int i, int j)
    {
        return min(height[i], height[j]) * (j - i);
    }
};