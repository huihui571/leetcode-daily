/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 785-判断二分图.cpp 
*   Author      : huihui571
*   Created date: 2021-02-27
*   Description : 存在一个 无向图 ，图中有 n 个节点。其中每个节点都有一个介于 0 到 n - 1 之间的唯一编号。
*   给你一个二维数组 graph ，其中 graph[u] 是一个节点数组，由节点 u 的邻接节点组成。
*   形式上，对于 graph[u] 中的每个 v ，都存在一条位于节点 u 和节点 v 之间的无向边。该无向图同时具有以下属性：
*       -不存在自环（graph[u] 不包含 u）。
*       -不存在平行边（graph[u] 不包含重复值）。
*       -如果 v 在 graph[u] 内，那么 u 也应该在 graph[v] 内（该图是无向图）
*       -这个图可能不是连通图，也就是说两个节点 u 和 v 之间可能不存在一条连通彼此的路径。
*   二分图 定义：如果能将一个图的节点集合分割成两个独立的子集 A 和 B ，并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B 集合，就将这个图称为 二分图 。
*   如果图是二分图，返回 true ；否则，返回 false 。

*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 染色法判断二分图
 * 使用图搜索算法从各个连通域的任一顶点开始遍历整个连通域，遍历的过程中用两种不同的颜色对顶点进行染色，相邻顶点染成相反的颜色。
 * 这个过程中倘若发现相邻的顶点被染成了相同的颜色，说明它不是二分图；反之，如果所有的连通域都染色成功，说明它是二分图。
 */
#if 0
/**
 * BFS
 */
 class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //由于图可能是不连通的，所以从每个顶点出发遍历一次
        for (int i = 0; i < graph.size(); i++) {
            if (!BFS(graph, i)) {
                return false;
            }
        }
        return true;
    }

    bool BFS(vector<vector<int>>& graph, int start) {
        vector<int> visited(graph.size(), 0);   //0表示未访问，1表示红色，2表示蓝色
        queue<int> Q;
        Q.push(start);
        visited[start] = 1;

        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();

            for (int w : graph[v]) {
                if (visited[w] == visited[v]) {
                    return false;   //如果当前节点的某个邻接节点已经访问过且颜色和当前节点相同，则返回false
                }
                //如果邻接点没访问过，那么把它染成和当前节点不一样的颜色,然后入队
                if (visited[w] == 0) {
                    if (visited[v] == 1) {
                        visited[w] = 2;
                    }
                    else if (visited[v] == 2) {
                        visited[w] = 1;
                    }
                    Q.push(w);
                }
            }
        }

        return true;
    }

};
#endif

#if 1
/**
 * DFS
 */
 class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), 0);   //0表示未访问，1表示红色，-1表示蓝色。这样换颜色直接取负就行了。
        //由于图可能是不连通的，所以从每个顶点出发遍历一次
        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i] && !DFS(graph, i, 1, visited)) {
                return false;
            }
        }
        return true;
    }
    
    //color是当前节点要被染的颜色
    bool DFS(vector<vector<int>>& graph, int cur, int color, vector<int>& visited) {
        if (visited[cur] != 0) {
            return visited[cur] == color;
        }
        
        visited[cur] = color;   //对当前节点染色
        for (int next : graph[cur]) {
            if (!DFS(graph, next, -color, visited)) {
                return false;
            }
        }

        return true;
    }
};
#endif
