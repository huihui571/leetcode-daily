/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 566-重塑矩阵.cpp 
*   Author      : huihui571
*   Created date: 2021-02-17
*   Description : 在MATLAB中，有一个非常有用的函数 reshape，它可以将一个矩阵重塑为另一个大小不同的新矩阵，但保留其原始数据。
*   给出一个由二维数组表示的矩阵，以及两个正整数r和c，分别表示想要的重构的矩阵的行数和列数。
*   重构后的矩阵需要将原始矩阵的所有元素以相同的行遍历顺序填充。
*   如果具有给定参数的reshape操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
* 二维-->一维：idx = i * cols + j
* 一维-->二维：i = idx / cols, j = idx % cols
*/
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int rows = nums.size();
        int cols = nums[0].size();
        if (rows * cols != r * c)
            return nums;
        
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < r * c; i++) {
            res[i / c][i % c] = nums[i / cols][i % cols];
        }
        return res;
    }
};
