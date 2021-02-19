/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 270-最接近的二叉搜索树值.cpp 
*   Author      : huihui571
*   Created date: 2021-01-24
*   Description : 给定一个不为空的二叉搜索树和一个目标值 target，请在该二叉搜索树中找到最接近目标值 target 的数值。
*   注意：
*   给定的目标值 target 是一个浮点数。
*   题目保证在该二叉搜索树中只会存在一个最接近目标值的数
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * 1.中序遍历
 * 2.二分搜索。根据当前根节点值与target大小关系，决定是向左还是向右搜索，搜索过程中维护一个最接近值。
 */
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int val, closeVal = root->val;
        while (root) {
            val = root->val;
            closeVal =  abs(val - target) < abs(closeVal - target) ? val : closeVal;
            if (target < root->val) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }  
        return closeVal;
    }
};
