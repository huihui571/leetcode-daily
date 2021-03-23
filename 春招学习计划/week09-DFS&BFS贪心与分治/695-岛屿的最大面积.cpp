/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 695-岛屿的最大面积.cpp
*   Author      : huihui571
*   Created date: 2021-03-18
*   Description : 给定一个包含了一些 0 和 1 的非空二维数组grid 。
*   一个岛屿是由一些相邻的1(代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设grid 的四个边缘都被 0（代表水）包围着。
*   找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)
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

