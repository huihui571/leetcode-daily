/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 037-解数独.cpp
*   Author      : huihui571
*   Created date: 2020-10-23
*   Description : 编写一个程序，通过填充空格来解决数独问题。
一个数独的解法需遵循如下规则：
    数字 1-9 在每一行只能出现一次。
    数字 1-9 在每一列只能出现一次。
    数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
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
 * 回溯+剪枝，和N皇后问题很像，就只是isValid函数的规则不一样而已
 */
class Solution
{
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        if (board.size() == 0)
            return;
        back_track(board);                
    }

    bool back_track(vector<vector<char>>& board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (!isValid(board, i, j, c))   //剪枝，不符合条件的
                            continue;   

                        board[i][j] = c;    //做选择
                        if (back_track(board))
                            return true;
                        board[i][j] = '.';  //撤销选择
                    }   
                    return false;   //在当前层，位置i,j找不到合适的数字 
                }
            }
        }
        return true;    //全部遍历结束
    }
    //验证字符c是否可以填在位置i,j
    bool isValid(vector<vector<char>>& board, int i, int j, char c)
    {
        //因为行、列和块都是有9个，因此可以在一个循环里搞定
        for (int k = 0; k < 9; ++k)
        {
            //检查行
            if (board[i][k] == c)
                return false;
            //检查列
            if (board[k][j] == c)
                return false;
            //检查块
            int b_i = (i / 3) * 3 + k / 3;
            int b_j = (j / 3) * 3 + k % 3;
            if (board[b_i][b_j] == c)
                return false;
        }
        return true;
    }
};