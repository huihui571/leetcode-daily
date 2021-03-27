/*<FH+>***************************************************************
*   Editor      : VSCode
*   File name   : 68-II-二叉树的最近公共祖先.cpp
*   Author      : huihui571
*   Created date: 2021-01-19
*   Description : 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
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
 * 递归后序遍历。
 * 转化为遍历寻找p,q的过程，对于当前一个root节点来说有四种情况：
 * 1. 左右子树中都没找到p、q，则返回空
 * 2. 左右子树分别找到p、q，说明当前节点就是LCA
 * 3. 左右子树一个找到p或q，另一个没找到，那就去找到那里面继续找
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return root;

        //递归终止
        if (p == root || q == root)
        {
            return root;
        }
        
        //去左右子树中找p,q
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (!left && !right)    //左右都没找到
        {
            return NULL;
        }
        else if (left && right) //左右都找到了
        {
            return root;
        }
        else if (left && !right)    //左边找到右边没找到
        {
            return left;
        }
        else                    //左边没找到右边找到了
        {
            return right;
        }
    }
};