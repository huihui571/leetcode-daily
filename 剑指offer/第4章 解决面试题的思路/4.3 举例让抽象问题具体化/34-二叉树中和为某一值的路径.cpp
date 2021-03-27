/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 34-二叉树中和为某一值的路径.cpp
*   Author      : huihui571
*   Created date: 2020-12-14
*   Description : 输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 先序遍历/回溯
 * 回溯代码风格：做选择之后在当前层判断，而不是到下一层的一开始去判断。
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(root, sum, res, path);
        return res;
    }

    //用sum做参数还得多传一个当前和的参数，改成target判断tar==0就行了
    void backtrack(TreeNode* root, int tar, vector<vector<int>>& res, vector<int>& path) {
         if (root == NULL)
            return;

        path.push_back(root->val);      //做选择
        tar -= root->val;

        if (tar == 0 && root->left == NULL && root->right == NULL) {    //左右子树都为空的是叶子节点
            res.push_back(path);
        }

        backtrack(root->left, tar, res, path);    //向下递归
        backtrack(root->right, tar, res, path);

        path.pop_back();                //撤销选择
    }
};
