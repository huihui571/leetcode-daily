/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 55-I-二叉树的深度.cpp
*   Author      : huihui571
*   Created date: 2021-01-02
*   Description : 输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
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


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return left > right ? (left + 1) : (right + 1);
    }
};
