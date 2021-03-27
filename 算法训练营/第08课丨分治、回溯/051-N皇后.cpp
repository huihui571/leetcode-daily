/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 051-N皇后.cpp
*   Author      : huihui571
*   Created date: 2020-07-30
*   Description : n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
*   给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
*   皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一到七步，可进可退
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
 * 回溯法经典问题
 * 这个问题本质上跟全排列问题差不多，决策树的每一层表示棋盘上的每一行；每个节点可以做出的选择是，在该行的任意一列放置一个皇后。
 * 路径：board 中小于 row 的那些行都已经成功放置了皇后
 * 选择列表：第 row 行的所有列都是放置皇后的选择
 * 结束条件：row 超过 board 的最后一行
 */
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        backtrack(res, board, 0);

        return res; 
    }

    void backtrack(vector<vector<string>>& res, vector<string> board, int row)
    {
        if (board.size() == row)
        {
            res.push_back(board);
            return;
        }

        int n = board[row].size();
        for (int col = 0; col < n; ++col)
        {
            if (!is_valid(board, row, col))
                continue;
            board[row][col] = 'Q';          //做选择
            backtrack(res, board, row + 1);   //下探到下一行
            board[row][col] = '.';          //撤销选择
        }
    }

    /* 是否可以在 board[row][col] 放置皇后？ */
    bool is_valid(vector<string>& board, int row, int col)
    {
        int n = board.size();
        //检查列
        for (int i = 0; i < n; ++i)
        { 
            if (board[i][col] == 'Q')
                return false;
        }
        // 检查右上方是否有皇后互相冲突
        for (int i = row - 1, j = col + 1; 
                i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        // 检查左上方是否有皇后互相冲突
        for (int i = row - 1, j = col - 1;
                i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};