/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 54-二叉搜索树的第k大节点.cpp
*   Author      : huihui571
*   Created date: 2021-01-02
*   Description : 给定一棵二叉搜索树，请找出其中第k大的节点。
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

/**
 * 反向中序遍历，右->根->左
 */
class Solution {
private:
    int res = -1, count = 0;
public:
    int kthLargest(TreeNode* root, int k) {
        inorder(root, k);
        return res;
    }
    void inorder(TreeNode* root, int k) {
        if (root == NULL)
            return;
        if (root->right)
            inorder(root->right, k);
        count++;
        if (count == k) {
            res = root->val;
            return;
        }
        if (root->left)
            inorder(root->left, k);
    }
};