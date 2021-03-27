/*<FH+>***************************************************************
*   Editor      : VSCode
*   File name   : 68-I-二叉搜索树的最近公共祖先.cpp
*   Author      : huihui571
*   Created date: 2021-01-18
*   Description : 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
* 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
* 满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）
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
 * 利用二叉搜索树根节点与左右子节点之间大小关系，缩小查找范围。
 * 若root大于p,q，则应该向左找
 * 若root小于p,q，则应该向右找
 * 若root在p,q之间或root等于p、q，则root就是最近公共祖先
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q)
        {
            return root;
        }
        if (root->val == p->val || root->val == q->val)
        {
            return root;
        }
        if ((root->val < p->val && root->val > q->val) || (root->val < q->val && root->val > p->val))
        {
            return root;
        }
        else if (root->val > p->val && root->val > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};