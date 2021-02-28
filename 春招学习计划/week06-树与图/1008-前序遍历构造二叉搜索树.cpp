/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 1008-前序遍历构造二叉搜索树.cpp 
*   Author      : huihui571
*   Created date: 2021-02-22
*   Description : 返回与给定前序遍历 preorder 相匹配的二叉搜索树（binary search tree）的根结点。
*   (回想一下，二叉搜索树是二叉树的一种，其每个节点都满足以下规则，对于 node.left 的任何后代，值总 < node.val，而 node.right 的任何后代，值总 > node.val。此外，前序遍历首先显示节点 node 的值，然后遍历 node.left，接着遍历 node.right。）
*   题目保证，对于给定的测试用例，总能找到满足要求的二叉搜索树。
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
 * 能够想到递归构造，关键就是函数参数怎么确定
 * 从划分区间入手，每次递归在前序数组中划分出[left] [left, mid - 1] [mid, right]即当前根节点，左子树节点，右子树节点
 * 因此只需要三个变量，mid可根据BST二叉搜索树的性质确定。
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildtree(preorder, 0, preorder.size() - 1);
    }

    TreeNode* buildtree(vector<int>& preorder, int left, int right) {
        if (left == right) {
            return new TreeNode(preorder[left]);
        }
        if (left > right) {
            return NULL;        //为NULL的叶子节点
        }

        int mid = left + 1;     //左右子树分界线
        while (mid <= right && preorder[mid] < preorder[left]) mid++;

        //[left] [left + 1, mid - 1] [mid, right]
        TreeNode* pRoot = new TreeNode(preorder[left]);
        pRoot->left = buildtree(preorder, left + 1, mid - 1);
        pRoot->right = buildtree(preorder, mid, right);

        return pRoot;
    }
};
