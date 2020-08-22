/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 094-二叉树的中序遍历.cpp
*   Author      : huihui571
*   Created date: 2020-07-27
*   Description : 给定一个二叉树，返回它的中序遍历。
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


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#if 0
/**
 * 递归版
 */
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;

        mid_order(root, res);

        return res;
    }

    //中序递归遍历，注意path需传引用进去
    void mid_order(TreeNode* root, vector<int>& path)
    {
        if (root == NULL)
            return;

        mid_order(root->left, path);
        path.push_back(root->val);
        mid_order(root->right, path);
    }
};
#endif

#if 1
/**
 * 迭代法
 */
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> st;

        TreeNode* cur = root;     
        while (cur != NULL || !st.empty())
        {   
            //向左走到最深
            while (cur != NULL)
            {
                st.push(cur);           //根指针进栈，遍历左子树
                cur = cur->left;
            }

            cur = st.top();             //退栈
            st.pop();
            res.push_back(cur->val);    //访问根节点
            cur = cur->right;           //再向右子树走
        }

        return res;
    }
};

#endif