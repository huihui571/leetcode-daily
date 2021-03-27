/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 32-II-从上到下打印二叉树-II.cpp
*   Author      : huihui571
*   Created date: 2020-12-14
*   Description : 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;

        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int q_size = Q.size();
            vector<int> cur_res;            //当前一层的结果
            for (int i = 0; i < q_size; ++i) {
                TreeNode* cur = Q.front();      //出队
                Q.pop();
                cur_res.push_back(cur->val);        //访问
                if (cur->left)                  //左右子节点入队
                    Q.push(cur->left);
                if (cur->right)
                    Q.push(cur->right);
            }
            res.push_back(cur_res);         //一层遍历结束
        }

        return res;
    }
};