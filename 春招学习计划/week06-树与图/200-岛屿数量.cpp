/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 200-岛屿数量.cpp 
*   Author      : huihui571
*   Created date: 2021-02-28
*   Description : 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
*   屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。此外，你可以假设该网格的四条边均被水包围。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 并查集解决连通性问题。
 * 遍历整个网格，对陆地执行合并操作（如果水域也合并的话要设置一个虚拟节点，将所有水域合并到该寻虚拟节点）
 * 最终岛屿的数量就是并查集中连通分量的个数
 * Note:需要有背景类（也就是水域），因为连通分量一开始被初始化为n，对背景进行union操作也会改变连通分量个数
 * 如果不加背景类的话最后的连通分量个数是不对的。除非一开始不将count初始化为n，而是初始化为岛的个数。
 */
class UnionFind {
    vector<int> parent;
    int count;
    //vector<int> rank;
 
public:
    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
        count = n;
    }
    ~UnionFind() {
    }

    int find_root(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];  //隔代压缩，x的parent指向它的祖父
            x = parent[x];
        }
        return x;
    }

    void union_tree(int x, int y) {
        int root_x = find_root(x);
        int root_y = find_root(y);

        if (root_x == root_y) {
            return;
        }

        parent[root_y] = root_x;
        count--;
    }

    int tree_count() {
        return count;
    }
};

class Solution {
private:
    int dir[2][2] = {{0, 1}, {1, 0}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        UnionFind uf(m * n + 1);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    for (int k = 0; k < 2; k++) {
                        int x = i + dir[k][0];
                        int y = j + dir[k][1];
                        if (x < 0 || x >= m || y < 0 || y >= n)
                            continue;
                        if (grid[x][y] == '1')
                            uf.union_tree(i * n + j, x * n + y); //连接两个'1'
                    }
                }
                else {
                    uf.union_tree(i * n + j, m * n);    //连接所有的'0'到虚拟节点
                }
            }
        }

        return uf.tree_count() - 1;
    }
};
