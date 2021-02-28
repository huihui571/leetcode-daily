/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 230-二叉搜索树中第K小的元素.cpp 
*   Author      : huihui571
*   Created date: 2021-02-25
*   Description : 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 /**
 * 中序遍历，记录节点个数
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        inorder(root, res, k);
        return res;
    }


    void inorder(TreeNode* root, int& res, int& k) {
        if (root == NULL)
            return;

        inorder(root->left, res, k);
        k--;
        if (k == 0) {
            res = root->val;
            return;
        }
        inorder(root->right, res, k);
    }
};
