/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 26-树的子结构.cpp
*   Author      : huihui571
*   Created date: 2020-12-10
*   Description : 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
B是A的子结构， 即 A中有出现和B相同的结构和节点值。
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
 * 先序遍历模板。先从根节点判断，若不是再分别往左右子树去判断
 */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL|| B == NULL)
            return false;

        //先从根节点判断B是不是A的子结构，如果不是在分别从左右两个子树判断
        return isSub(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool isSub(TreeNode* A, TreeNode* B) {
        //如果B为空，说明B访问完了，都是A的子结构
        if (B == NULL)
            return true;
        //如果B不为空A为空，或者节点值不等，直接返回false
        if (A == NULL || A->val != B->val)
            return false;
        //继续比较左右子节点
        return isSub(A->left, B->left) && isSub(A->right, B->right);
    }
};