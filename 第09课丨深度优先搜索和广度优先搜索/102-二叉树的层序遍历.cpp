/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 102-二叉树的层序遍历.cpp
*   Author      : huihui571
*   Created date: 2020-07-30
*   Description : 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
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
 * 层序遍历，使用队列
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        queue<TreeNode*> q;
      
        if (root == NULL)
            return res;  

        q.push(root);       //根节点先入队
        while (!q.empty())
        {
            vector<int> level;
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i)  //队列中为同一层
            {
                TreeNode* cur = q.front();  //出队，访问之
                q.pop();
                level.push_back(cur->val);
                if (cur->left) 
                    q.push(cur->left);          //子节点入队
                if (cur->right)
                    q.push(cur->right);
            }
            res.push_back(level);
        }

        return res;     
    }
};