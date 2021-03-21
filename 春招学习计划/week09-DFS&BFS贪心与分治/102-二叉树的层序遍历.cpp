/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 102-二叉树的层序遍历.cpp
*   Author      : huihui571
*   Created date: 2021-03-17
*   Description : 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
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


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty()) {
            vector<int> level;
            int q_size = Q.size();
            for (int i = 0; i < q_size; ++i) {
                TreeNode* cur = Q.front();
                Q.pop();
                level.push_back(cur->val);
                if (cur->left)
                    Q.push(cur->left);
                if (cur->right)
                    Q.push(cur->right);
            }
            res.push_back(level);
        }

        return res;
    }
};

