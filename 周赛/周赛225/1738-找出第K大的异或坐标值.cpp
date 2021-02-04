/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 1738-找出第K大的异或坐标值.cpp 
*   Author      : huihui571
*   Created date: 2021-01-24
*   Description : 给你一个二维矩阵 matrix 和一个整数 k ，矩阵大小为 m x n 由非负整数组成。
*   矩阵中坐标 (a, b) 的 值 可由对所有满足 0 <= i <= a < m 且 0 <= j <= b < n 的元素 matrix[i][j]（下标从 0 开始计数）执行异或运算得到。
*   请你找出 matrix 的所有坐标中第 k 大的值（k 的值从 1 开始计数）。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = matrix[0][0];
        
        for (int i = 1; i < m; ++i) {
            dp[i][0] = matrix[i][0] ^ dp[i - 1][0];
        }
        
        for (int j = 1; j < n; ++j) {
            dp[0][j] = matrix[0][j] ^ dp[0][j - 1];
        }
        
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << dp[i][j] << ", ";
        //     }
        //     cout << endl;
        // }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = (dp[i - 1][j] ^ dp[i][j - 1]) ^ dp[i - 1][j - 1] ^ matrix[i][j];
            }
        }
        
        vector<int> arr;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                arr.push_back(dp[i][j]);
                // cout << dp[i][j] << ", ";
            }
            // cout << endl;
        }
        sort(arr.begin(), arr.end());
        
        return arr[m*n - k];
        
    }
};
