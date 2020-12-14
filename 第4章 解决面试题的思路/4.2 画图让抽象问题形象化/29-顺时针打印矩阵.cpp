/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 29-顺时针打印矩阵.cpp
*   Author      : huihui571
*   Created date: 2020-12-11
*   Description : 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
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
 * 将向右、向下、向左、向上这样一圈作为一个整体，循环执行。每执行完一圈后，重新设置起点，缩短长宽，遍历里面一圈。
 * 直到圈的长宽为0
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>  res;
        if (matrix.empty() || matrix[0].empty())
            return res;
        int height = matrix.size();
        int width = matrix[0].size();

        int x = 0, y = 0;   //起点，下面每一圈循环的坐标相对于这个锚点来表示
        while (width > 0 && height > 0) {
            for (int i = 0; i < width; ++i)
            {
                res.push_back(matrix[x][y + i]);
            }
            for (int i = 1; i < height; ++i)
            {
                res.push_back(matrix[x + i][y + width - 1]);
            }
            if (height > 1) 
            {
                for (int i = width - 2; i >= 0; --i)
                {
                    res.push_back(matrix[x + height - 1][y + i]);
                }  
            }
            if (width > 1)
            {
                for (int i = height - 2; i > 0; --i)
                {
                    res.push_back(matrix[x + i][y]);
                }      
            }
 
            //重新设置下一圈的起点和长宽
            x += 1;
            y += 1;
            width -= 2;
            height -= 2;
        }

        return res;
    }
};