/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 32-I-从上到下打印二叉树.cpp
*   Author      : huihui571
*   Created date: 2020-12-14
*   Description : 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
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
 * 层序遍历
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;

        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int q_size = Q.size();
            for (int i = 0; i < q_size; ++i) {
                TreeNode* cur = Q.front();      //出队
                Q.pop();
                res.push_back(cur->val);        //访问
                if (cur->left)                  //左右子节点入队
                    Q.push(cur->left);
                if (cur->right)
                    Q.push(cur->right);
            }
        }

        return res;
    }
};
