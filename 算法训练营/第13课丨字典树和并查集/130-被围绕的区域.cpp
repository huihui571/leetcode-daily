/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 130-被围绕的区域.cpp
*   Author      : huihui571
*   Created date: 2020-10-18
*   Description : 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
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

#if 0
/**
 * DFS法，从边界的O开始dfs，将与之相连的O都置成@。最后再遍历整个棋盘，将@还原成O，将O置成X
 */
class Solution 
{
private:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
public:
    void solve(vector<vector<char>>& board)
    {
        int num_row = board.size();
        if (!num_row)
            return;
        int num_col = board[0].size();

        //顶边和底边
        for (int j = 0; j < num_col; j++)
        {
            if (board[0][j] == 'O')
                dfs(board, 0, j);
            if (board[num_row - 1][j] == 'O')
                dfs(board, num_row - 1, j);
        }

        //左侧边和右边
        for (int i = 0; i < num_row; i++)
        {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][num_col - 1] == 'O')
                dfs(board, i, num_col - 1);
        }
        
        //开始替换
        for (int i = 0; i < num_row; ++i)
        {
            for (int j = 0; j < num_col; ++j)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '@')
                    board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
        if (board[i][j] != 'O')
            return;

        board[i][j] = '@';

        for (int k = 0; k < 4; ++k)
        {
            int new_i = i + dx[k];
            int new_j = j + dy[k];
            dfs(board, new_i, new_j);
        }
    }
};
#endif

#if 1
/**
 * 并查集法，设置一个哑节点，将与边界O连通的O全部和哑节点合并成一类。最后将所有不和哑节点一类的O置成X
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

    /*两个节点是否连通*/
    bool is_connected(int x, int y)
    {
        return find_root(x) == find_root(y);
    }
};


class Solution 
{
private:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
public:
    void solve(vector<vector<char>>& board)
    {
        int num_row = board.size();
        if (!num_row)
            return;
        int num_col = board[0].size();
        UnionFind uf(num_row * num_col + 1);    //加一个哑节点

        for (int i = 0; i < num_row; ++i)
        {
            for (int j = 0; j < num_col; ++j)
            {
                if (board[i][j] == 'X')
                    continue;
                //边界的O和哑节点合并
                if (i == 0 || i == num_row - 1|| j == 0 || j == num_col - 1)
                {
                    uf.union_tree(i * num_col + j, num_row * num_col);
                }
                else
                {
                    //和上下左右合并
                    for (int k = 0; k < 4; ++k)
                    {
                        int new_i = i + dx[k];
                        int new_j = j + dy[k];
                        if (new_i < 0 || new_i >= num_row || new_j < 0 || new_j >= num_col)
                            continue;
                        if (board[new_i][new_j] == 'X')
                            continue;
                        uf.union_tree(new_i * num_col + new_j, i * num_col + j);
                    }                    
                }          
            }
        }
   
        
        //开始替换
        for (int i = 0; i < num_row; ++i)
        {
            for (int j = 0; j < num_col; ++j)
            {
                if (board[i][j] == 'O' && !uf.is_connected(i * num_col + j, num_row * num_col))
                    board[i][j] = 'X';
            }
        }
    }

};
#endif