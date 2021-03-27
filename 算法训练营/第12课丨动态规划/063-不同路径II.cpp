/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 063-不同路径II.cpp
*   Author      : huihui571
*   Created date: 2020-09-22
*   Description : 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
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

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        if (obstacleGrid.empty())
            return -1;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        //初始化
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; ++i)
        {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; ++j)
        {
            dp[0][j] = 1;
        }

        //递推
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 1)    //如果是障碍物
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];     //状态转移
                }
            }
        }

        return dp[m-1][n-1];
    }
};