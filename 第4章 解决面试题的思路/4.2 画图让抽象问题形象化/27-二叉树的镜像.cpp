/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 27-二叉树的镜像.cpp
*   Author      : huihui571
*   Created date: 2020-12-11
*   Description : 请完成一个函数，输入一个二叉树，该函数输出它的镜像。
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

/**
 * 递归地翻转左右子树，当前层就是把指向左右子树的指针互换
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        
        TreeNode* left  = mirrorTree(root->left);
        TreeNode* right = mirrorTree(root->right);

        root->left = right;
        root->right = left;

        return root;
    }
};