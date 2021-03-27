/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 078-子集.cpp
*   Author      : huihui571
*   Created date: 2020-07-30
*   Description : 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。
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
 * 回溯法
 */
class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> path;
        int n = nums.size();

        res.push_back(path);    //[]也算答案
        backtrack(res, path, nums, 0, n);
        return res;  
    }

    void backtrack(vector<vector<int>>& res, vector<int> path, vector<int>&nums, int start, int n)
    {
        if (path.size() == n)
        {
            return;
        }

        for (int i = start; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);        //不用等到叶子节点再添加结果
            res.push_back(path);
            backtrack(res, path, nums, i + 1, n);
            path.pop_back();
        }
    }
};

/**
 * 迭代法
 */