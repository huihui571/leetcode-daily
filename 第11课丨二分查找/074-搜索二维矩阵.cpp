/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 074-搜索二维矩阵.cpp
*   Author      : huihui571
*   Created date: 2020-09-17
*   Description : 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
    每行中的整数从左到右按升序排列。
    每行的第一个整数大于前一行的最后一个整数。
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
 * 当成一个按行排列的一维数组，二分法查找。
 */
class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();      

        int left = 0, right = m * n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target == matrix[mid / n][mid % n - 1])
            {
                return true;
            }
            else if (target > matrix[mid / n][mid % n - 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        } 

        return false;
    }
};