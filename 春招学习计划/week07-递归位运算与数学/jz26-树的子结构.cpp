/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : jz26-树的子结构.cpp
*   Author      : huihui571
*   Created date: 2021-03-03
*   Description : 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
*   B是A的子结构， 即 A中有出现和B相同的结构和节点值。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 要用两个递归
 */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL)
            return false;

        if (isSub(A, B))    //先判断A根节点，如果不是再往左右子树去判断
            return true;
        else
            return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool isSub(TreeNode* A, TreeNode* B) {
        if (B == NULL)
            return true;
        if (A == NULL)      //B不为空A却为空了，返回false
            return false;

        if (A->val == B->val)
            return isSub(A->left, B->left) && isSub(A->right, B->right);
        else
            return false;
    }
};
