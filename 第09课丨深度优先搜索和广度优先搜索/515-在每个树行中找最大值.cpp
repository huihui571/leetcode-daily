/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 515-在每个树行中找最大值.cpp
*   Author      : huihui571
*   Created date: 2020-08-20
*   Description : 您需要在二叉树的每一行中找到最大的值。
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
 * 层次遍历时，统计每一层的最大值
 */
class Solution
{
public:
    vector<int> largestValues(TreeNode* root)
    {
        vector<int> res;
        queue<TreeNode*> q;

        if (root == NULL)
            return res;

        q.push(root);           //根节点入队
        while (!q.empty())
        {
            int lev_max = INT_MIN;
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i)
            {
                TreeNode* cur = q.front();      //出队
                q.pop();
                if (cur->val > lev_max)
                    lev_max = cur->val;

                if (cur->left)                  //左右节点入队
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            res.push_back(lev_max);
        }

        return res;
    }
};