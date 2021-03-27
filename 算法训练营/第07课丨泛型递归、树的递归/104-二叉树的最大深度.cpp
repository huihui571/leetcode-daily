/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 104-二叉树的最大深度.cpp
*   Author      : huihui571
*   Created date: 2020-07-28
*   Description : 给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明: 叶子节点是指没有子节点的节点。
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

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return helper(root);
        
    }
    int helper(TreeNode* root) {
        if (root == NULL) 
            return 0;

        int leftDepth = helper(root->left);
        int rightDepth = helper(root->right);

        return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
    }
};