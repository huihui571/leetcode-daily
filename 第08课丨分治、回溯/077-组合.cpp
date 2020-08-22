/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 077-组合.cpp
*   Author      : huihui571
*   Created date: 2020-07-29
*   Description : 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
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

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(0, res, path, 1, n, k);  

        return res;
    }

    void backtrack(int level, vector<vector<int>>& res, vector<int> path, int start, int n, int k)
    {
        if (level == k)
        {
            res.push_back(path);    //满足条件,添加路径
            return;
        }

        for (int i = start; i <= n; ++i)    
        {
            path.push_back(i);      //做选择
            backtrack(level + 1, res, path, i + 1, n, k);
            path.pop_back();        //撤销选择
        }
    }
};