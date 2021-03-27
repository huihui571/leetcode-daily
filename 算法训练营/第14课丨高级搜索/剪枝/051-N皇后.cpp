/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 051-N皇后.cpp
*   Author      : huihui571
*   Created date: 2020-10-23
*   Description : n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
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
 * 经典回溯+剪枝，要先自己new一个棋盘出来，然后一行一行或者一列一列试探(放皇后)
 */
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));    //创建棋盘

        back_track(res, board, 0);

        return res;
    }

    //一列一列放
    void back_track(vector<vector<string>>& res, vector<string>& board, int col)
    {
        if (col == board.size())    //递归终止
        {
            res.push_back(board);
            return;
        }

        for (int i = 0; i < board.size(); ++i)
        {
            if (!isValid(board, i, col))
                continue;           //不合法的位置，剪枝

            board[i][col] = 'Q';
            back_track(res, board, col + 1);
            board[i][col] = '.';   
        }      
    }
    
    //判断在row,col处放置一个皇后是否合法
    bool isValid(const vector<string>& board, int row, int col)
    {
        //检查行(左侧)，因为一列只放一个所以不检查列
        for (int i = 0; i < col; ++i)
        {
            if (board[row][i] == 'Q')
                return false;
        }
        //检查左上方
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0 ; --i, --j)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        //检查左下方
        for (int i = row + 1, j = col - 1; i < board.size() && j >= 0 ; ++i, --j)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};