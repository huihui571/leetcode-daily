/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 200-岛屿数量.cpp
*   Author      : huihui571
*   Created date: 2021-03-18
*   Description : 给你一个由'1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
*   岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
*   此外，你可以假设该网格的四条边均被水包围。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * BFS
 * 使用二维坐标：队列里传pair<>，访问标记用visited[][]
 */
class Solution {
private:
    static constexpr int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1 && !visited[i][j])
                    res = max(res, BFS(grid, i, j, visited));
            }
        }

        return res;
    }

    int BFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        visited[i][j] = true;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int curX = front.first;
            int curY = front.second;
            count++;

            for (int k = 0; k < 4; k++) {
                int newX = curX + dir[k][0];
                int newY = curY + dir[k][1];
                if (newX < 0 || newX >= m || newY < 0 || newY >= n)
                    continue;
                if (grid[newX][newY] == 0 || visited[newX][newY])
                    continue;
                q.push(make_pair(newX, newY));
                visited[newX][newY] = true;
            }
        }

        return count;
    }
};

