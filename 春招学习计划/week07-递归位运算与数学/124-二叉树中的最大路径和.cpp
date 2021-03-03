/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 124-二叉树中的最大路径和.cpp 
*   Author      : huihui571
*   Created date: 2021-03-01
*   Description : 路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
*   路径和 是路径中各节点值的总和。
*   给你一个二叉树的根节点 root ，返回其 最大路径和 。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 * 计算子树的最大贡献值，最大贡献值等于子树跟节点加上其左右子树的最大贡献值中较大的
 * 因为通往上层的路径不可能同时经过左子树和右子树
 * 当前节点为跟的树的最大路径和=当前节点值+左子树最大贡献+右子树最大贡献
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT32_MIN;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* root, int& res) {
        if (root == NULL) {
            return 0;
        }
        
        //贡献需大于0
        int left = max(dfs(root->left, res), 0);
        int right = max(dfs(root->right, res), 0);

        res = max(res, root->val + left + right);  //路径和
        
        return root->val + max(left, right);  //贡献; 
    }
};
