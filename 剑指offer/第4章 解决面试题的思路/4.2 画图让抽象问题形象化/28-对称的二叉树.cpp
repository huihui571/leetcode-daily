/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 28-对称的二叉树.cpp
*   Author      : huihui571
*   Created date: 2020-12-11
*   Description : 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
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
 * 前序遍历，两个指针，同时前序遍历两个树，边遍历边比较。
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        return isSymmetric(root->left, root->right);
    }

    //前序遍历，判断两个树是否对称
    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
        //递归终止条件，两个树都到叶子节点了，整个树都对称
        if (root1 == NULL && root2 == NULL)
            return true;

        //如果有一个节点为空，或者两个节点的值不等，返回false
        if (root1 == NULL || root2 == NULL || root1->val != root2->val)
            return false;
        
        //递归地判断树1的左子树与树2的右子树，树1的右子树和树2的左子树，是否对称
        return isSymmetric(root1->right, root2->left) && isSymmetric(root1->left, root2->right); 
    }
};