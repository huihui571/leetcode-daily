/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 111-二叉树的最小深度.cpp
*   Author      : huihui571
*   Created date: 2020-03-30
*   Description : 给定一个二叉树，找出其最小深度。
*   最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
*   说明：叶子节点是指没有子节点的节点。
*
*<FH->***************************************************************/
#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * 另一种BFS写法，用dist数组记录源点到每个点的最短距离，而不是level变量。这样不需要在队列中for循环，和spfa和dijkstra写法统一。
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        unordered_map<TreeNode*, int> dist;
        // vector<bool> visited;

        q.push(root);
        // visited[source] = true;
        dist[root] = 1;

        while (!q.empty()) {
            TreeNode* u = q.front();
            q.pop();
            // cout << "cur: " << u->val << endl;

            if (u->left == NULL && u->right == NULL) {
                return dist[u];
            }

            if (u->left) {
                dist[u->left] = dist[u] + 1;
                q.push(u->left);
            }
            if (u->right) {
                dist[u->right] = dist[u] + 1;
                q.push(u->right);
            }
        }

        return -1;
    }

    //BFS求source到target的最短路径
    // int BFS(unordered_map<int, vector<int>>& G, int n, int source, int target)
    // {
    //     queue<int> q;
    //     vector<int> dist(n + 1, 0);
    //     vector<bool> visited(n + 1, false);

    //     q.push(source);
    //     visited[source] = true;
    //     dist[source] = 0;

    //     while (!q.empty()) {
    //         int u = q.front();
    //         q.pop();
    //         cout << "cur: " << u << endl;
    //         for (auto v : G[u]) {
    //             if (!visited[v]) {
    //                 dist[v] = dist[u] + 1;
    //                 q.push(v);
    //                 visited[v] = true;  
    //             }
    //         }
    //     }

    //     return dist[target];
    // }
};
