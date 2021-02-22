/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 119-杨辉三角II.cpp 
*   Author      : huihui571
*   Created date: 2021-02-13
*   Description : 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 动态规划递推，空间优化，注意内层数组遍历方向
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);
        row[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j >= 1; j--) {
                row[j] = row[j] + row[j - 1];   //反向遍历才能保证等号右边的都是上一层的旧值 
            }
        }
        return row;
    }
};
