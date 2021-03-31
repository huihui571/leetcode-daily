/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 787-K站中转内最便宜的航班.cpp
*   Author      : huihui571
*   Created date: 2021-03-31
*   Description : 有 n 个城市通过 m 个航班连接。每个航班都从城市 u 开始，以价格 w 抵达 v。
*   现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到从 src 到 dst 最多经过 k 站中转的最便宜的价格。 
*   如果没有这样的路线，则输出 -1。
*   提示：
*       n 范围是 [1, 100]，城市标签从 0 到 n - 1
*       航班数量范围是 [0, n * (n - 1) / 2]
*       每个航班的格式 (src, dst, price)
*       每个航班的价格范围是 [1, 10000]
*       k 范围是 [0, n - 1]
*       航班没有重复，且不存在自环
*
*<FH->***************************************************************/
#include <bits/stdc++.h>
using namespace std;

#if 0
/**
 * 带权图的最短路径，有一个限制条件：最多经过K站中转。
 * Dijkstra算法，堆优化
 * Note:航班没有重复，且不存在环路，因此可以不用visit控制
 */
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int, int>>> G;   //<u, <w, v>>
        for (auto flight : flights) {
            G[flight[0]].push_back({flight[2], flight[1]});
        }
        using Edge = tuple<int, int, int>;  //<d, cnt, v>
        priority_queue<Edge, vector<Edge>, greater<Edge>> q;
        const int INF = INT_MAX / 2;
        vector<int> dist(n + 1, INF);
        vector<bool> visited(n + 1, false);     //是否已找到最短路径

        dist[src] = 0;
        q.push({0, 0, src});

        while (!q.empty()) {
            auto cur = q.top();
            q.pop();
            // auto [d, cnt, u] = cur;  //结构化绑定是c++17新特性
            int d, cnt, u;
            tie(d, cnt, u) = cur;   //std::tie用来解包
            // cout << "d: " << d << " cnt: " << cnt << " u: " << u << endl;
            //检查限制条件
            if (cnt > K + 1) {
                continue;
            }
            //  cout << "d: " << d << " cnt: " << cnt << " u: " << u << endl;
            //找到终点
            if (u == dst) {
                return d;
            }

            // visited[u] = true;

            for (auto neighbor: G[u]) {
                int w = neighbor.first, v = neighbor.second;
                // if (/*!visited[v] &&*/ dist[v] > d + w) {
                    // cout << "v: " << v << endl;
                    dist[v] = d + w;
                    q.push({dist[v], cnt + 1, v});
                // }
            }
        }

        return -1;
    }
};
#endif


#if 1
/**
 * 带权图的最短路径，有一个限制条件：最多经过K站中转。
 * Dijkstra每一次都是选到当前点最短的路径（贪心），然后再往后走，但是由于步数的限制，导致到当前最短的路径到后面可能超限而被排除。
 * 所以在入队前不需要那一步松弛操作。
 * 这个题没有重复的点，没有环，所以也不需要visited。
 * 既然这样那其实就退化成普通的BFS了，每一条路径都要尝试，节点也可能重复入队。
 */
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int, int>>> G;   //<u, <w, v>>
        for (auto flight : flights) {
            G[flight[0]].push_back({flight[2], flight[1]});
        }
        using Edge = tuple<int, int, int>;  //<d, cnt, v>
        queue<Edge> q;
        const int INF = INT_MAX / 2;

        int res = INF;  //把dist放进节点信息里了，这里只需要记录一个最终最优的答案就行了
        q.push({0, 0, src});

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int d, cnt, u;
            tie(d, cnt, u) = cur;   //std::tie用来解包

            if (cnt > K + 1) {
                continue;
            }

            //找到终点
            if (u == dst) {
                res = min(res, d);  //能顺利到dst的路径里面，选最短的。
                //其实只在这一步取最小值就行，用优先队列相当于每一步都取最小的路径先开始，不过对前面的节点没影响，只是会增加一点时间复杂度。
            }

            for (auto neighbor: G[u]) {
                int w = neighbor.first, v = neighbor.second;
                if (d + w > res) 
                    continue;   //剪枝，大于res的没必要入队了。不加这个会超时
                q.push({d + w, cnt + 1, v});   
            }
        }

        return res == INF ? -1 : res;
    }
};
#endif