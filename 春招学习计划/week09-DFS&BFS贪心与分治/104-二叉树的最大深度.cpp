/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 104-二叉树的最大深度.cpp
*   Author      : huihui571
*   Created date: 2021-03-15
*   Description : 给定一个二叉树，找出其最大深度。
*   二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
*   说明: 叶子节点是指没有子节点的节点。
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

#if 0
/**
 * DFS法
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
#endif

#if 1
/**
 * BFS法
 */
class Solution {
    int level = 0;
public:
    int maxDepth(TreeNode* root) {
        BFS(root);
        return level;
    }

    void BFS(TreeNode* root) {
        if (root == NULL)
            return;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i) {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            level++;
        }
    }
};
#endif
