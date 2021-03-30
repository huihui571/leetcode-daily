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
// BFS求source到target的最短路径
int BFS(unordered_map<int, vector<int>>& G, int n, int source, int target)
{
    queue<int> q;
    vector<int> dist(n + 1, 0);
    vector<bool> visited(n + 1, false);

    q.push(source);
    visited[source] = true;
    dist[source] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << "cur: " << u << endl;
        for (auto v : G[u]) {
            if (!visited[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
                visited[v] = true;  
            }
        }
    }

    return dist[target];
}
#endif

#if 0
/**
 * 朴素Dijkstra
 */
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = INT_MAX / 2;    //使用INT_MAX/2避免后面有INT_MAX+INT_MAX导致int溢出

        //定义二维数组来存储图，即邻接矩阵
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

#if 0
/**
 * 优先队列优化Dijkstra
 * while(优先队列非空)
 * -->队头出队，松弛它的边
 * -->松弛了的<新距离,点>入队
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

#if 1
/**
 * SPFA算法
 * while(队非空)
 * -->队头出队，松弛它的边
 * -->松弛了且不在队内的点入队
 * 和BFS基本框架很像，主要是一个节点出队之后还可能再次入队，而如果一个节点入队超过n次就说明存在负环。
 */
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = INT_MAX / 2;
        unordered_map<int, vector<pair<int, int>>> G;   //<u, <w,v>>
        queue<int>  q;
        vector<int> dist(n + 1, INF);
        vector<bool> visited(n + 1, false); //标记的是当前节点是否在队列里，所以出队之后还要置为false。

        //初始化邻接表
        for (auto t : times) {
            G[t[0]].push_back({t[2], t[1]});
        }

        q.push(k);
        dist[k] = 0;
        visited[k] = true;

        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            visited[u] = false;     //这里与BFS不同

            for (auto neighbor : G[u]) {
                auto w = neighbor.first, v = neighbor.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;      //松弛
                    if (!visited[v]) {      //如果不在队列里，则入队
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
        }

        int res = *max_element(dist.begin() + 1, dist.end());
        return res == INF ? -1 : res;
    }
};
#endif