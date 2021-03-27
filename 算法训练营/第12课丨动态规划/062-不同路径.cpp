/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 062-不同路径.cpp
*   Author      : huihui571
*   Created date: 2020-09-22
*   Description : 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
问总共有多少条不同的路径
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
 * dp[i][j]表示到坐标(i,j)的路径条数。由于机器人从i=0,j=0出发，每次只能向下或者向右移动，
 * 因此，在所有坐标为（0，j)的位置机器人要到达的话只有一条路径（一直向下）；在所有坐标为（i,0)的位置，机器人要到达也只有一条路径（一直向右）。
 * 而要到达任一位置(i,j)的总路径条数，总是等于「 位置(i-1,j)的路径条数」 加上 「位置（i，j-1)的路径条数」。
 * 因此，dp[i][j] = dp[i-1][j] + dp[i][j-1]
 */
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 0 || n == 0)
            return 0;

        int dp[m][n];
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 1;       //边界只有一种走法      
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];     //状态转移方程
                }
            }
        }

        return dp[m-1][n-1];    //左上角
    }
};
#endif

/**
 * dp数组用一个就行，每次计算一行的dp值。dp[j] = dp[j] + dp[j-1]
 */
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 0 || n == 0)
            return 0;
        //初始化
        vector<int> dp(n, 1);   //最底下一行全是1
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n-1];
    }
};