/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 120-三角形最小路径和.cpp
*   Author      : huihui571
*   Created date: 2020-09-25
*   Description : 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
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

/**
 * 动态规划
 * 从三角形底边开始往上推
 * d[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + a[i][j]
 * 空间优化，只用一行 dp[j] = min(dp[j], dp[j+1]) +a[j]
 */
class Solution
{
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int n = triangle.size();    //正三角形m=n
        vector<int> dp(n, 0);
        //初始化
        for (int i = 0; i < n; ++i)
        {
            dp[i] = triangle[n-1][i];
        }
        //从倒数第二行开始递推
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = 0; j <= i; ++j)
            {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];  
            }
        }

        return dp[0];
    }
};


#if 0
/**
 * 动态规划
 * dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
 * 在三角形边界 j == 0 和 j == i 时要特殊处理
 */
class Solution
{
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        if (triangle.empty())
            return -1;
        int n = triangle.size();    //正三角形m=n

        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < n; ++i)     //从1开始
        {
            //j == 0
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            for (int j = 1; j < i; ++j)
            {
   
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            }
            //j == i
            dp[i][i] = dp[i-1][i-1] + triangle[i][i]; 
        }
        sort(dp[n-1].begin(), dp[n-1].end());
        return dp[n-1].front();
    }
};
#endif