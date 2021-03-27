/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 13-机器人的运动范围.cpp
*   Author      : huihui571
*   Created date: 2020-11-30
*   Description : 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，
*   它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
*   例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
*   请问该机器人能够到达多少个格子？
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
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
 * 不需要撤销选择，所以严格来说只是dfs，不算回溯
 */
class Solution {
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    int movingCount(int m, int n, int k) {

        int res = 1;
        vector<bool> visited(m * n, false);
        back_track(m, n, k, 0, 0, res, visited);

        return res;
    }

    void back_track(int m, int n, int k, int row, int col, int& res, vector<bool>& visited) {
        if (row < 0 || row >= m || col < 0 || col >= n)
            return;
        if ((row / 10) + (row % 10) + (col / 10) + (col % 10) > k || visited[row * n + col])
            return;

        res++; 
        visited[row * n + col] = true;
        for (int i = 0; i < 4; ++i)
        {
            int new_i = dx[i] + row;
            int new_j = dy[i] + col;
            back_track(m, n, k, new_i, new_j, res, visited);
        }     
    }
};