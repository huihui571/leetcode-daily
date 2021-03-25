/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 743-网络延迟时间.cpp
*   Author      : huihui571
*   Created date: 2021-03-22
*   Description : 有 n 个网络节点，标记为1到 n。
*   给你一个列表times，表示信号经过 有向 边的传递时间。times[i] = (ui, vi, wi)，其中ui是源节点，vi是目标节点， wi是一个信号从源节点传递到目标节点的时间。
*   现在，从某个节点K发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回-1 。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#if 0
/**
 * 朴素Dijkstra
 */
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = INT_MAX / 2;    //使用INT_MAX/2避免后面有INT_MAX+INT_MAX导致int溢出

        //定义二维数组来存储图，即邻接表
        vector<vector<int>> g(n + 1, vector<int>(n + 1, INF));
        for (auto t : times) {
            g[t[0]][t[1]] = t[2];   //起点-终点-权重
        }

        vector<int> dist(n + 1, INF);   //起点到各节点的最短路径
        for (int i = 1; i <= n; ++i) { //初始化为各边权重，不可直达的初始化为INF
            dist[i] = g[k][i];
        }
        dist[k] = 0;                //起点到自己初始化为0

        vector<bool> visited(n + 1, false); //标记到该节点的最短路径是否已找到
        visited[k] = true;

        //主循环
        for (int i = 1; i < n; ++i) {
            //在所有未确定最短路径的节点中，找到离源点最近的节点
            int minDis = INF;
            int minIdx = 0;
            for (int j = 1; j <= n; ++j) {
                if (!visited[j] && dist[j] != INF && dist[j] < minDis) {
                    minDis = dist[j];
                    minIdx = j;
                }
            }

            visited[minIdx] = true;     //到这一点的最短路径已经确定

            //根据刚刚找到的最短距离的点，去更新其它点到源点的距离
            for (int j = 1; j <=n; ++j) {
                if (g[minIdx][j] != INF) {
                    dist[j] = min(dist[j], dist[minIdx] + g[minIdx][j]);    //如果有边相连的话，进行松弛操作
                }
            }
        }

        //答案处理，返回最大距离。注意dist[0]是无效的。
        int ret = *max_element(dist.begin() + 1, dist.end());
        return ret == INF ? -1 : ret;
    }
};
#endif

#if 1
/**
 * 优先队列优化Dijkstra
 * 选队列中最小的，即离源点最近的点出队，然后松弛该点的所有邻接节点。
 */
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = INT_MAX / 2;
        unordered_map<int, vector<pair<int, int>>> G;   //定义邻接表，<u, <v, w>>
        vector<int> dist(n + 1, INF);       //源点到各点的最短距离
        vector<bool> visited(n + 1, false); //是否已找到最短路径
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //小顶堆，维护到源点的最短距离和点

        //初始化邻接表
        for (auto t : times) {
            G[t[0]].push_back({t[1], t[2]});
        }

        //起点入队
        q.push({0, k});     //<d, u>距离放前面，因为pair默认按第一个元素的大小排序
        dist[k] = 0;
        // visited[k] = true;  //visited不能和BFS一样在入队后马上置位，而是应该在出队时置位。因为visited实际上不是访问标志，而是标记到当前节点的最短路径是否已经找到。

        while (!q.empty()) {
            //出队的是未确定最短路径的节点中离源点最近的点
            auto cur = q.top();
            q.pop();
            int d = cur.first, u = cur.second;

            if (visited[u])
                continue;
            visited[u] = true;

            //松弛cur所有的邻接节点
            for (auto& neighbor : G[u]) {
                auto v = neighbor.first, w = neighbor.second;
                if (dist[v] > d + w) {
                    dist[v] = d + w;        //松弛
                    q.push({dist[v], v});   //邻接点入队
                }
            }
        }
        
        int res = *max_element(dist.begin() + 1, dist.end());
        return res == INF ? -1 : res;
    }
};
#endif