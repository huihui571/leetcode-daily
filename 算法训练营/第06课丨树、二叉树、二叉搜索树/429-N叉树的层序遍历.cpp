/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 429-N叉树的层序遍历.cpp
*   Author      : huihui571
*   Created date: 2020-07-27
*   Description : 给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。
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


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/**
 * BFS
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        vector<vector<int>> res;
        queue<Node*> q;

        if (root == NULL)
            return res;

        q.push(root);
        while (!q.empty())
        {
            int q_size = q.size();
            vector<int> cur_level;
            for (int i = 0; i < q_size; ++i)    //队列中是这一层节点，依次出队处理
            {
                Node* cur = q.front();              //依次出队
                q.pop();
                cur_level.push_back(cur->val);      //访问
                for (Node* ch : cur->children)      //子节点依次入队
                {
                    q.push(ch);
                }
            }
            res.push_back(cur_level);
        }

        return res;
    }
};