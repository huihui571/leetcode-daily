/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 200-岛屿数量.cpp
*   Author      : huihui571
*   Created date: 2020-08-20
*   Description : 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
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

#if 0
/**
 * 广度优先搜索
 * 扫描整个二维网格。如果一个位置为 111，则将其加入队列，开始进行广度优先搜索。
 * 在广度优先搜索的过程中，每个搜索到的 111 都会被重新标记为 000。直到队列为空，搜索结束。
 */
class Solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int res = 0;

        int num_row = grid.size();
        if (!num_row)
            return res;
        int num_col = grid[0].size();

        for (int i = 0; i < num_row; i++)
        {
            for (int j = 0; j < num_col; j++)
            {
                /**从图的每一个点作为起点出发进行bfs**/
                if (grid[i][j] == '1')
                {
                    res++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> neighbors;
                    neighbors.push({i, j});                 //队列中存当前点的坐标

                    while (!neighbors.empty())
                    {
                        auto cur = neighbors.front();
                        neighbors.pop();
                        int row = cur.first;
                        int col = cur.second;
                        /**分别向上下左右四个方向遍历**/
                        if (row - 1 >= 0 && grid[row - 1][col] == '1')
                        {
                            neighbors.push({row - 1, col});             //入队
                            grid[row - 1][col] = '0';                              //置访问标记
                        }

                        if (row + 1 < num_row && grid[row + 1][col] == '1')
                        {
                            neighbors.push({row + 1, col});
                            grid[row + 1][col] = '0'; 
                        }

                        if (col - 1 >= 0 && grid[row][col - 1] == '1')
                        {
                            neighbors.push({row, col - 1});
                            grid[row][col - 1] = '0';
                        }
                        
                        if (col + 1 < num_col && grid[row][col + 1] == '1')
                        {
                            neighbors.push({row, col + 1});
                            grid[row][col + 1] = '0';
                        }
                    }
                    
                }
            }
        }
        
        return res;
    }
};
#endif

/**
 * 我们可以将二维网格看成一个无向图，竖直或水平相邻的 111 之间有边相连。
 * 为了求出岛屿的数量，我们可以扫描整个二维网格。如果一个位置为 111，则以其为起始节点开始进行深度优先搜索。在深度优先搜索的过程中，每个搜索到的 111 都会被重新标记为 000。
 * 最终岛屿的数量就是我们进行深度优先搜索的次数。
 */
class Solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int res = 0;
        int num_row = grid.size();
        if (!num_row)
            return res;
        int num_col = grid[0].size();
        for (int i = 0; i < num_row; ++i)
        {
            for (int j = 0; j < num_col; ++j)
            {
                if (grid[i][j] == '1')
                {
                    res++;              //起始位置
                    dfs(grid, i, j);    //开始深度优先搜索
                }
            }

        }

        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        int num_row = grid.size();
        int num_col = grid[0].size();

        grid[i][j] = '0';       //置访问标记
        //开始向上搜索
        if (i - 1 >= 0 && grid[i - 1][j] == '1')
            dfs(grid, i - 1, j);
        //开始向下搜索
        if (i + 1 < num_row && grid[i + 1][j] == '1')
            dfs(grid, i + 1, j);
        //开始向左搜索
        if (j - 1 >= 0 && grid[i][j - 1] == '1')
            dfs(grid, i, j - 1);
        //开始向右搜索
        if (j + 1 < num_col && grid[i][j + 1] == '1')
            dfs(grid, i, j + 1);
    }
};