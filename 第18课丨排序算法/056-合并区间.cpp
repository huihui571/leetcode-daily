/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 056-合并区间.cpp
*   Author      : huihui571
*   Created date: 2020-11-08
*   Description : 给出一个区间的集合，请合并所有重叠的区间。
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
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
 * 先将区间按照其左端点排序，然后将第一个区间加入，之后依次考虑每个区间：
 *     如果当前左端点在res最后一个区间右端点之外，则不重合，这是一个新区间
 *     否则说明重合，此时应更新res最后一个区间右端点
 */
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> res;
        if (intervals.size() == 0)
            return {};

        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); ++i)
        {
            int start = intervals[i][0], end = intervals[i][1];
            if (res.empty() || start > res.back()[1])  //start落在区间外
                res.push_back({start, end});        //新的一段
            else    
                res.back()[1] = max(res.back()[1], end);    //更新end
        }

        return res;
    }
};