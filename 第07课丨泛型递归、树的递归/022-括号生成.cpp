/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 022-括号生成.cpp
*   Author      : huihui571
*   Created date: 2020-07-28
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

/**
 * 回溯法的代码套路是使用两个变量： res 和 path，res 表示最终的结果，path 保存已经走过的路径。如果搜到一个状态满足题目要求，就把 path 放到 res 中。
 * 思路：一开始是一个(，然后每一步开始“做选择”，选择1是下一步添加一个(，选择2是添加一个)，所以此题的决策树是一棵二叉树。
 * 可以采用DFS求解，遍历决策树，叶子节点就是我们的答案。
 * 过程需要剪枝，因为不是所有的排列都是合法的括号，剪枝规则：
 * 1.插入括号总数不超过n
 * 2.右括号不能大于当前左括号数量
 */
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        int left_cnt=0, right_cnt=0;        //左右括号数量
        
        dfs(res, "", n, left_cnt, right_cnt);
        return res;
    }

    void dfs(vector<string>& res, string path, int n, int left_cnt, int right_cnt)
    {
        if (left_cnt > n || right_cnt > n || right_cnt > left_cnt)
            return;

        if (left_cnt == n && right_cnt == n)  //到叶子节点了,保存一个路径
        {
            res.push_back(path);
            return;
        }

        dfs(res, path + '(', n, left_cnt + 1, right_cnt);     //添加一个左括号(左子树)
        dfs(res, path + ')', n, left_cnt, right_cnt + 1);     //添加一个右括号(右子树)
    }
};