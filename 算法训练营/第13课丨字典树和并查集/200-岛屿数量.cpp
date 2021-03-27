/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 200-岛屿数量.cpp
*   Author      : huihui571
*   Created date: 2020-10-20
*   Description : 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
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

#if 1
/**
 * 并查集法，通过设置一个哑节点(背景类)，让所有的水域都合并到背景类，则最终合并的结果减1就是岛屿数量
 */
class UnionFind
{
private:
    int count;      //记录连通分量
    int* parent;    //是一个数组，节点x的父节点是parent[x]
public:
    /*构造函数*/
    UnionFind(int n)
    {
        this->count = n; //一开始互不连通
        parent = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;      //父节点指针初始指向自己
        }
    }

    /*返回某个节点的根节点*/
    int find_root(int x)
    {
        //根节点有parent[x] == x
        while (parent[x] != x)
        {
            parent[x] = parent[parent[x]];  //这一句进行路径压缩，将x提到和x的父亲并列的层级
            x = parent[x];
        }
        return x;
    }

    /*合并x,y所在的两棵树*/
    void union_tree(int x, int y)
    {
        int root_x = find_root(x);
        int root_y = find_root(y);

        if (root_x == root_y)
            return;

        parent[root_x] = root_y;  //把x挂到y上面去
        count--;                //连通分量-1
    }

    /*返回连通量个数*/
    int tree_count()
    {
        return this->count;
    }
};

class Solution
{
private:
int dx[4] = {0, 1};
int dy[4] = {1, 0};

public:
    int numIslands(vector<vector<char>>& grid)
    {
        int res = 0;
        int num_row = grid.size();
        if (!num_row)
            return 0;
        int num_col = grid[0].size();

        UnionFind uf(num_row * num_col + 1);    //最后位置增加一个哑节点(背景)，所有0都和它一类

        for (int i = 0; i < num_row; ++i)
        {
            for (int j = 0; j < num_col; ++j)
            {
                if (grid[i][j] == '1')
                {
                    for (int k = 0; k < 2; k++)     //没必要四个方向，向右向下遍历就行了
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];

                        if (x < 0 || x >= num_row || y < 0 || y >= num_col)
                            continue;
                        if (grid[x][y] == '0')
                            continue;

                        uf.union_tree(i * num_col + j, x * num_col + y);
                    }       
                }
                else
                {
                    uf.union_tree(i * num_col + j, num_row * num_col);  //合并到背景类
                }
            }
        }

        return uf.tree_count() - 1; //减去背景类
    }
};
#endif

#if 0
/**
 * DFS法
 */
class Solution
{
private:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int res = 0;
        int num_row = grid.size();
        if (!num_row)
            return 0;
        int num_col = grid[0].size();

        for (int i = 0; i < num_row; ++i)
        {
            for (int j = 0; j < num_col; ++j)
            {
                if (grid[i][j] == '1')    //从1开始dfs
                {
                    res++;              //岛屿的数量就是dfs的次数
                    dfs(grid, i, j);
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        if (grid[i][j] == '0')
            return;

        grid[i][j] = '0';   //置访问标记

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            dfs(grid, x, y);
        }
    }
};
#endif