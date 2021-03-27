/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 047-全排列II.cpp
*   Author      : huihui571
*   Created date: 2020-07-29
*   Description : 给定一个可包含重复数字的序列，返回所有不重复的全排列。
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
 * 思路：先排序，然后重复的数字就变成相邻的了，添加进路径的时候去重剪枝就行了
 */
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> path;
        int n = nums.size();
        vector<bool> is_used(nums.size(), 0);       //标记元素是否访问过
        sort(nums.begin(), nums.end());

        backtrack(res, path, nums, n, is_used);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int> path, vector<int>& nums, int n, vector<bool>& is_used)
    {
        if (path.size() == n)
        {
            res.push_back(path);    //满足条件，添加路径到结果
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (is_used[i])                     //去掉已经访问过的
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && !is_used[i - 1]) //去掉重复的
                continue;
            path.push_back(nums[i]);
            is_used[i] = true;
            backtrack(res, path, nums, n, is_used);
            path.pop_back();
            is_used[i] = false;         //别忘了回溯时撤销访问标记
        }

    }
};