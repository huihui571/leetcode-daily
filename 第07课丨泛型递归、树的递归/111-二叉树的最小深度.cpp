/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 111-二叉树的最小深度.cpp
*   Author      : huihui571
*   Created date: 2020-07-28
*   Description : 给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
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


/**
 * 叶子节点的定义是左孩子和右孩子都为 null 时叫做叶子节点
 * 当 root 节点左右孩子都为空时，返回 1
 * 当 root 节点左右孩子有一个为空时，返回不为空的孩子节点的深度
 * 当 root 节点左右孩子都不为空时，返回左右孩子较小深度的节点值
 */
class Solution
{
public:
    int minDepth(TreeNode* root)
    {
        if (root == NULL)
            return 0; 

        //左右孩子都为空，才说明到叶子节点，返回1
        if (root->left == NULL && root->right == NULL)
            return 1;

        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        //左右有一个为空，返回不空的+1； 左右都不为空，返回最小深度+1
        if (root->left == NULL || root->right == NULL)
            return leftDepth + rightDepth + 1;      //此时左右必有一个为0
        else
            // return leftDepth < rightDepth ? leftDepth + 1 : rightDepth + 1;
            return min(leftDepth, rightDepth) + 1;      
    }

};