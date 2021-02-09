#include <bits/stdc++.h>
using namespace std;
//并查集模板
class UnionFind {
public:
    vector<int> parent; //节点x的父节点是parent[x]
    vector<int> size;   //记录树的节点数目，以便按秩合并
    int count;  //连通分量数目
public:
    UnionFind(int _n) : parent(_n), count(_n), size(_n, 1) {
        for (int i = 0; i < _n; i++) {
            parent[i] = i;      //一开始parent指向自己
        }
    }

    int find_root(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];  //路径压缩
            x = parent[x];
        }
        return x;
    }

    bool union_tree(int x, int y) {
        int root_x = find_root(x);
        int root_y = find_root(y);

        if (root_x == root_y) {
            return true;
        }

        if (size[root_x] < size[root_y]) {
            swap(root_x, root_y);
        }
        parent[root_y] = root_x;    //将节点少的树合并到节点多的树上去
        size[root_x] += size[root_y];

        count--;    //连通分量减一
        return true;
    }

    bool is_connect(int x, int y) {
        return find_root(x) == find_root(y);
    }

    int tree_count() {
        return count;
    }
};

#if 0
/**
 * 1. 二分查找的妙用。
 * 由于本题求的是“最小体力消耗值”，所以可以用二分查找来搜索这样一个值：
 * 小于这个值的话，无法从起点走到终点；大于等于这个值，则可以从起点走到终点。是二分查找中的lowe_bound模型。
 * 判断能否从起点走到终点，则是一个图的连通性问题，可以用BFS或者并查集来求解。
 */
class Solution {
private:
    static constexpr int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int left = 0, right = 999999;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // bool isConnected = BFS(heights, mid);
            bool isConnected = UF(heights, mid);
            // cout << isConnected <<  " | left: " << left << " ,mid :" << mid << " ,right: " << right << endl;
            if (!isConnected) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }

    //BFS判断在不超过当前cost的前提下，起点和终点能否连通
    bool BFS(vector<vector<int>>& heights, int cost) {
        int m = heights.size(), n = heights[0].size();
        queue<pair<int, int>> Q;
        vector<bool> visited(m * n, false); //visited无论是数组还是hashSet都需要转化成一维，i*N+j来唯一标记一个位置。
        Q.emplace(0, 0);    //起点入队
        visited[0] = true;

        while (!Q.empty()) {
            //队首节点出队
            auto [x, y] = Q.front();
            Q.pop();

            //访问邻接节点
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                //判断邻接节点是否合法
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx * n + ny] && abs(heights[nx][ny] - heights[x][y]) <= cost) {
                    //邻接节点入队，记访问标志
                    Q.emplace(nx, ny);
                    visited[nx * n + ny] = true;
                }
            }
        }

        return visited[m * n - 1];
    }

    //并查集判断起点能否和终点连通
    bool UF(vector<vector<int>>& heights, int cost) {
        int m = heights.size(), n = heights[0].size();
        UnionFind uf(m * n);
        vector<bool> visited(m * n, false);
        
        //遍历网格，将符合条件的节点全部连接
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    int ni = i + dir[k][0];
                    int nj = j + dir[k][1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni * n + j] && abs(heights[i][j] - heights[ni][nj]) <= cost) {
                        uf.union_tree(i * n + j, ni * n + nj);
                        visited[ni * n + nj] = true;
                    }
                }
            }
        }

        return uf.is_connect(0, m * n - 1);
    }
};
#endif

#if 0
/**
 * 2. 并查集改进
 * 将整个矩阵看成一个图的各个节点，边的权值即为相邻两节点的差值。将节点放入并查集中，并实时维护它们的连通性。
 * 每次从边集合中取一条权值最小的边，进行合并操作。当加入一条权值为x的边之后，如果起点和终点连接起来了，那么x即为答案。
 * 每次取权值最小的边，可以通过先sort实现，也可以用优先队列实现。
 */
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<tuple<int, int, int>> edges; //权值，边起点，边终点
        
        //构建边集合
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int pos = i * n + j;    //坐标转化成一维
                if (i < m - 1) {
                    edges.emplace_back(abs(heights[i + 1][j] - heights[i][j]), pos, pos + n);
                }
                if (j < n - 1) {
                    edges.emplace_back(abs(heights[i][j + 1] - heights[i][j]), pos, pos + 1);
                }
            }
        }

        //排序
        sort(edges.begin(), edges.end(), [](const auto& e1, const auto& e2) {
            auto [w1, x1, y1] = e1;
            auto [w2, x2, y2] = e2;
            return w1 < w2;
        });

        //合并
        UnionFind uf(m * n);
        for (const auto [w, x, y] : edges) {
            uf.union_tree(x, y);
            if (uf.is_connect(0, m * n - 1)) {
                return w;
            }
        }
        return -1;
    }
};
#endif

#if 1
/**
 * 3. SPFA算法
 * SPFA(Shortest Path Faster Algorithm)是求单源最短路径的一种算法，它是Bellman-ford的队列优化，同时相比于Dijkstra它可以处理负权边，是一种十分高效的最短路径算法。
 * 实现方法：建立一个队列，初始时队列里只有起点，再建立一个表格记录起始点到所有点的最短路径。然后执行松弛操作，用队列里的点去刷新
 * 起始点到所有点的最短路径，如果刷新成功且被刷新点不在队列里则把该点加入队列末尾。重复执行直到队列为空。
 * 此外，SPFA算法还可以判断图中是否有负权环，即一个点入队次数超过N。
 */
class Solution {
private:
    static constexpr int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        using Edge = tuple<int, int, int>;  //距离，起点，终点
        priority_queue<Edge, vector<Edge>, greater<Edge>> Q;    //greater<>是降序即小顶堆。tuple默认比较大小是从第一个元素开始比较，相等则比较第二个元素
        Q.emplace(0, 0, 0);

        vector<int> dist(m * n, INT32_MAX);    //起点到各个节点的最短距离
        dist[0] = 0;    //除到自己为0，其余初始化为无穷大
        vector<bool> visited(m * n);
        visited[0] = true;

        while (!Q.empty()) {
            auto [d, x, y] = Q.top();
            Q.pop();
            
            //if (visited[x * n + y])
            //    continue;
            //if (x == m - 1 && y == n - 1) {
            //    break;      //到达终点
            //}
            //visited[x * n + y] = true;

            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int cur_dist = max(d, abs(heights[nx][ny] - heights[x][y]));    //“最短路径”定义为其经过的所有边权值的最大值，而不是其经过所有边权的和
                    if (cur_dist < dist[nx * n + ny] && !visited[nx * n + ny]) {
                        dist[nx * n + ny] = cur_dist;   //松弛
                        Q.emplace(dist[nx * n + ny], nx, ny);
                        visited[nx * n + ny] = true;
                    }
                }
            }
        }

        return dist[m * n - 1];
    }
};
#endif
