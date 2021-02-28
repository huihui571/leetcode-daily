/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 230-二叉查找树中第K小的元素II.cpp 
*   Author      : huihui571
*   Created date: 2021-02-22
*   Description : 给定一个二叉搜索树，我们希望找到其中第 k 小的元素。
*   在这道题目中，除了原始的二叉搜索树 root 以外，你还会得到一个和其结构完全一致的二叉树 nodenum_root，树上节点的值代表以该节点为根的子树的节点数量。
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * 中序遍历。没有用到nodenum信息，时间复杂度O(n)
 * 二分查找。时间复杂度O(logn)
 */
class Solution {
public:
    int kthSmallestII(TreeNode* root, TreeNode* nodenum_root, int k) {
        int num = 0; //左子树节点个数。num+1即当前节点在中序序列中位置
        if (nodenum_root->left) {
            num = nodenum_root->left->val;
        }
        
        if (num + 1 == k) {
            return root->val;
        }
        else if (num + 1 > k) {
            return kthSmallestII(root->left, nodenum_root->left, k);
        }
        else {
            return kthSmallestII(root->right, nodenum_root->right, k - num - 1);
        }
        return - 1;
    }
};
