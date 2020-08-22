/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 144-二叉树的前序遍历.cpp
*   Author      : huihui571
*   Created date: 2020-07-27
*   Description : 给定一个二叉树，返回它的 前序 遍历。
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
    vector<int> preorderTraversal(TreeNode* root)
    { 
        vector<int> res;

        pre_order(root, res);

        return res;
    }

    //前序递归遍历，注意path需传引用进去
    void pre_order(TreeNode* root, vector<int>& path)
    {
        if (root == NULL)
            return;

        path.push_back(root->val);
        pre_order(root->left, path);
        pre_order(root->right, path);
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
    vector<int> preorderTraversal(TreeNode* root)
    { 
        vector<int> res;
        stack<TreeNode*> st;

        TreeNode* cur = root;
        while (cur != NULL || !st.empty())
        {
            while (cur != NULL)             //向左走到最深
            {
                res.push_back(cur->val);    //访问根节点
                st.push(cur->right);        //右子树入栈
                cur = cur->left;   
            }

            cur = st.top();         //栈顶元素是最靠下的右子树
            st.pop();
        }
        return res;
    }
};
#endif