/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 098-验证二叉搜索树.cpp
*   Author      : huihui571
*   Created date: 2020-07-28
*   Description : 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
假设一个二叉搜索树具有如下特征：
- 节点的左子树只包含小于当前节点的数。
- 节点的右子树只包含大于当前节点的数。
- 所有左子树和右子树自身必须也是二叉搜索树。
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
 * 递归法，中序遍历
 * 如果当前节点小于等于中序遍历的前一个节点，说明不满足BST，返回 false；否则继续遍历。
 */
class Solution
{
private:
    int pre = INT32_MIN;
public:
    bool isValidBST(TreeNode* root)
    {
        if (root == NULL)
            return true;

        // 访问左子树
        if (!isValidBST(root->left))
            return false;
        
        // 访问当前节点，做判断
        if (root->val <= pre)
            return false;
        pre = root->val;

        // 访问右子树
        return isValidBST(root->right);
    }
};
#endif

#if 1
/**
 * 迭代法，中序遍历
 * 如果当前节点小于等于中序遍历的前一个节点，说明不满足BST，返回 false；否则继续遍历。
 */
class Solution
{
public:
    bool isValidBST(TreeNode* root)
    {
        stack<TreeNode*> st;
        TreeNode* cur = root;

        long long pre = INT64_MIN;

        while (cur != NULL || !st.empty())
        {
            //向左走到最深
            while (cur != NULL)
            {
                st.push(cur);
                cur = cur->left;
            }

            //出栈，访问之
            cur = st.top();
            st.pop();
            if (cur->val <= pre)
                return false;
            pre = cur->val;

            //向右走
            cur = cur->right;
        }

        return true;
    }
};
#endif