/*<FH+>***************************************************************
*   Editor      : Visual Studio 2019
*   File name   : 04-二维数组中的查找.cpp
*   Author      : huihui571
*   Created date: 2020-11-21
*   Description : 在一个二维数组中，每一行都按照从左至右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
* 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
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
* 选择右上角的数据进行比较，因为右上角是一列中最小的，同时又是一行中最大的。(也可以选择左下角的数据)
*/
class Solution {
public:
    bool findInTable(vector<vector<int>>& nums, int target) {
        int rows = nums.size(), cols = nums[0].size();
        int i = 0, j = cols - 1;

        while (i < rows && col >= 0) {
            if (nums[i][j] == target) {
                return true;
            }
            else if (nums[i][j] > target) {
                j--;
            }
            else {
                i++;
            }
        }

        return false;
    }
};
