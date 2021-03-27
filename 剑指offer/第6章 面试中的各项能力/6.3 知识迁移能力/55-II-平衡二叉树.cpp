/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 55-II-平衡二叉树.cpp
*   Author      : huihui571
*   Created date: 2021-01-02
*   Description : 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
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

#if 0
/**
 * 先序遍历+判断深度
 * 每个节点在递归判断和递归求深度的时候，被遍历多次，效率不高。
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        if (left - right > 1 || left - right < -1)      //先判断当前是不是
            return false;

        return isBalanced(root->left) && isBalanced(root->right);   //再递归判断左右子树是不是
    }

    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return left > right ? (left + 1) : (right + 1);
    }
};
#endif

#if 1
/**
 * 后序遍历+剪枝
 * 把统计高度和判断是否平衡同时进行，返回高度的同时，用返回-1表示不平衡。
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return recur(root) != -1;
    }

    int recur(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = recur(root->left);       //先递归判断左右
        if (left == -1)
            return -1;      //剪枝
        int right = recur(root->right);
        if (right == -1)
            return -1;

        return abs(left - right) < 2 ? max(left, right) + 1 : -1;   //再判断当前
    }
};
#endif

