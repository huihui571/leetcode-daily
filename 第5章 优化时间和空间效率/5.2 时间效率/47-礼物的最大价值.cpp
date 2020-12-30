/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 47-礼物的最大价值.cpp
*   Author      : huihui571
*   Created date: 2020-12-30
*   Description : 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
*   你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
*   给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
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
 * 动态规划
 */
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        
        dp[0][0] = grid[0][0];          //初始化
        for (int i = 1; i < m; ++i)     //初始化第一列
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < n; ++i)     //初始化第一行
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};