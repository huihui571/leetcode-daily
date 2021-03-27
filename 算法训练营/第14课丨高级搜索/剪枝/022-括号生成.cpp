/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 022-括号生成.cpp
*   Author      : huihui571
*   Created date: 2020-10-21
*   Description : 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
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

#if 0
/**
 * 递归+剪枝。这一道是经典的剪枝思想解决问题。
 */
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string path;

        helper(res, path, 0, 0, n);

        return res;
    }

    void helper(vector<string>&res, string& path, int left, int right, int n)
    {
        if (left > n)   //左括号大于n，剪枝
            return;
        if (right > left)   //右括号数量大于左，剪枝
            return;

        if (left == n && right == n)    //满足条件，保存结果
            res.push_back(path);

        /**下面是经典回溯思路*/
        path += '(';            //做选择
        helper(res, path, left + 1, right, n);  //下探
        path.pop_back();        //撤销选择

        path += ')';
        helper(res, path, left, right + 1, n);
        path.pop_back();
    }
};
#endif

#if 1
/**
 * 动态规划
 * p[i]表示i组括号的所有有效组合
 * dp[i] = "(" + dp[p]的所有有效组合 + ")" + dp[q]的组合，其中 1 + p + q = i , p从0遍历到i-1, q则相应从i-1到0
 */
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        dp[1] = {"()"};

        for (int i = 2; i < n + 1; ++i)
        {
            /**每次做选择可以理解为在上一步答案基础上插入一对新括号，为这对括号选择插入位置。
               把左括号插入到整个答案的最左边，那么现在要为右括号选择一个插入位置，
                右括号插入会把原来的括号分为两个部分，p个括号和q个括号，p+q=i-1，
                这里p和q本身都是成对的，那么就可以从之前的dp状态中获得。
            **/
            for (int j = 0; j < i; ++j)
            {
                vector<string> list_p = dp[j];
                vector<string> list_q = dp[i - 1 - j];
                for (string p : list_p)     //p从0到i-1
                {
                    for (string q : list_q)     //q从i-1到0
                    {
                        string str = "(" + p + ")" + q;
                        dp[i].push_back(str);
                    }
                }
            }
        }

        return dp[n];
    }
};
#endif