/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 1740-找到二叉树中的距离.cpp 
*   Author      : huihui571
*   Created date: 2021-02-22
*   Description : 给定一棵二叉树的根节点 root 以及两个整数 p 和 q ，返回该二叉树中值为 p 的结点与值为 q 的结点间的 距离 。
*   两个结点间的 距离 就是从一个结点到另一个结点的路径上边的数目。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
class Solution {
public:
    int findDistance(TreeNode* root, int p, int q) {
        TreeNode* node = LCA(root, p, q);

        int resp = 0, resq = 0;
        preOrder(node, p, 0, resp);
        preOrder(node, q, 0, resq);
        return resp + resq;
    }


    //前序求根节点到指定节点的距离。deep记录深度，res保存结果
    void preOrder(TreeNode* root, int target, int deep, int& res) {
        if (root == NULL) {
            return;
        }
        
        if (root->val == target) {
            res = deep;
            return;
        }
        preOrder(root->left, target, deep + 1, res);
        preOrder(root->right, target, deep + 1, res);
    }

    //求最近公共祖先
    TreeNode* LCA(TreeNode* root, int p, int q) {
        if (root == NULL)
            return NULL;
        if (root->val == p || root->val == q)
            return root;

        TreeNode* left = LCA(root->left, p, q);     
        TreeNode* right = LCA(root->right, p, q);  

        if (left == NULL && right == NULL)
            return NULL;
        else if (left && right == NULL)
            return left;            //去左子树寻找
        else if (left == NULL && right)
            return right;           //去右子树寻找
        else 
            return root;            //当前就是
    }
};
