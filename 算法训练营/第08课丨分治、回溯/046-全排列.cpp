/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 046-全排列.cpp
*   Author      : huihui571
*   Created date: 2020-07-29
*   Description : 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
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
    // vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> res;
        int n = nums.size();
        vector<int> path;

        backtrack(res, nums, path, n);
        return res;    
    }

    void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int> path, int n)
    {
        if (path.size() == n)
        {
            res.push_back(path);    //满足条件，添加路径
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (find(path.begin(), path.end(), nums[i]) != path.end())    //已经添加过的不再重复添加
                continue;
            path.push_back(nums[i]);      //做选择
            backtrack(res, nums, path, n);
            path.pop_back();        //取消选择
        }
    }
};