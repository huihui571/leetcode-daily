/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 1091-二进制矩阵中的最短路径.cpp
*   Author      : huihui571
*   Created date: 2020-10-24
*   Description : 在一个 N × N 的方形网格中，每个单元格有两种状态：空（0）或者阻塞（1）。
一条从左上角到右下角、长度为 k 的畅通路径，由满足下述条件的单元格 C_1, C_2, ..., C_k 组成：
    相邻单元格 C_i 和 C_{i+1} 在八个方向之一上连通（此时，C_i 和 C_{i+1} 不同且共享边或角）
    C_1 位于 (0, 0)（即，值为 grid[0][0]）
    C_k 位于 (N-1, N-1)（即，值为 grid[N-1][N-1]）
    如果 C_i 位于 (r, c)，则 grid[r][c] 为空（即，grid[r][c] == 0）
返回这条从左上角到右下角的最短畅通路径的长度。如果不存在这样的路径，返回 -1 。
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
 * BFS
 */
class Solution
{
private:
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0,  -1};
    int dy[8] = {0,  1, 1, 1, 0, -1, -1, -1};

    // struct node 
    // {
    //     int value;
    //     int row;
    //     int col;
    //     node(int _value, int _row, int _col): value(_value), row(_row), col(_col) {}
    // };
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int step = 1;

        queue<pair<int, int>> Q;
        // unordered_set<pair<int, int>> visited;   //FIXME:自定义类型要为其实现一个哈希函数
        vector<vector<int>> visited(grid.size(), vector<int>(grid.size()));

        Q.push(make_pair(0, 0));
        // visited.insert(make_pair(0, 0));
        visited[0][0] = 1;
        

        while (!Q.empty())
        {
            int q_size = Q.size();
            for (int i = 0; i < q_size; ++i)
            {
                pair<int, int> cur = Q.front();
                int row = cur.first;
                int col = cur.second;
                Q.pop();

                if (grid[row][col] == 1)    //应该是当前==0才继续寻路，这里用continue使程序简洁
                    continue;

                if (row == grid.size() - 1 && col == grid.size() - 1)
                    return step;

                for (int j = 0; j < 8; ++j)
                {
                    int new_x = row + dx[j];
                    int new_y = col + dy[j];

                    if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid.size() 
                        || visited[new_x][new_y] == 1)
                        continue;

                    Q.push(make_pair(new_x, new_y));
                    visited[new_x][new_y] = 1;
                }
            }
            step++;
        }
        return -1;  //别忘了到最后这里表面没有找到通路，返回-1
    }
};

#if 0
/**
 * 动态规划，还没有AC
 */
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        if (n == 1)
            return grid[0][0] == 0 ? 1 : -1;
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return - 1;

        dp[0][0] = 1;
        dp[0][1] = grid[0][1] == 0 ? 2 : INT32_MAX;
        dp[1][0] = grid[1][0] == 0 ? 2 : INT32_MAX;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if ((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 0))
                    continue;

                if (grid[i][j] == 1)
                    dp[i][j] = INT32_MAX;
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1];
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j];
                else
                {
                    int old = min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j]));
                    dp[i][j] =  old == INT32_MAX ? INT32_MAX: old + 1;
                }
                    
            }
        }

        return dp[n - 1][n - 1] == INT32_MAX ? -1 : dp[n - 1][n - 1];
    }
};
#endif