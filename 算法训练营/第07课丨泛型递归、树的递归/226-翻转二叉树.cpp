/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 226-翻转二叉树.cpp
*   Author      : huihui571
*   Created date: 2020-07-27
*   Description : 翻转一棵二叉树。
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

/**
 * 递归
 * 其核心在于遍历到每一个节点，接触到每一个节点就能反转它的左右孩子，至于前序还是后序并不重要。
 */
class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == NULL)
            return root;

        TreeNode* left = invertTree(root->left);    //递归地反转左右子树，返回反转后根节点
        TreeNode* right = invertTree(root->right);
        root->left = right;                         //反转当前节点的两个孩子
        root->right = left;
        return root;
    }
    // TreeNode* invertTree(TreeNode* root)
    // {
    //     invert_tree(root);

    //     return root;
    // }

    // //翻转二叉树，递归
    // void invert_tree(TreeNode* root)
    // {
    //     if (root == NULL)
    //         return;

    //     invert_tree(root->left);
    //     invert_tree(root->right);
    //     TreeNode* temp = root->left;
    //     root->left = root->right;
    //     root->right = temp;
    // }
};