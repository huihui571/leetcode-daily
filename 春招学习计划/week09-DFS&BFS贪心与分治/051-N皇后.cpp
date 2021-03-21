/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 051-N皇后.cpp
*   Author      : huihui571
*   Created date: 2021-03-16
*   Description : n皇后问题 研究的是如何将 n个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
*   给你一个整数 n ，返回所有不同的n皇后问题 的解决方案。
*   每一种解法包含一个不同的n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 基于集合的回溯。
 * 为了判断一个位置所在的列和两条对角线上是否已经有皇后，使用三个集合cols、diags1、diags2分别
 * 记录每一列以及两个方向的对角线上是否有皇后。
 * 集合用set比数组更方便，用数组要注意对角线怎么表示，以及处理偏移。
 */
class Solution {
private:
    vector<bool> cols, diags1, diags2;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));    //创建棋盘
        cols.resize(n);
        diags1.resize(2 * n - 1);   //主对角线
        diags2.resize(2 * n - 1);   //副对角线

        backTrack(res, 0, board);
        return res;
    }

    void backTrack(vector<vector<string>>& res, int row, vector<string>& board) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }

        //对于第row行的每一个位置，尝试放置
        for (int col = 0; col < board.size(); ++col) {
            if (cols[col] || diags1[col - row + board.size() - 1] || diags2[col + row]) {
                continue;
            }

            board[row][col] = 'Q';
            cols[col] = true;
            diags1[col - row + board.size() - 1] = true;
            diags2[col + row] = true;
            backTrack(res, row + 1, board);
            board[row][col] = '.';
            cols[col] = false;
            diags1[col - row + board.size() - 1] = false;
            diags2[col + row] = false;
        }
    }
};

