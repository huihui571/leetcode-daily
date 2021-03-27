/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 529-扫雷游戏.cpp
*   Author      : huihui571
*   Created date: 2020-09-08
*   Description : 让我们一起来玩扫雷游戏！
给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。
现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：
    如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
    如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。
    如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
    如果在此次点击中，若无更多方块可被揭露，则返回面板。
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
 * dfs遍历修改
 */
class Solution
{
private:
    int offset_x[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int offset_y[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
    {
        // vector<vector<char>> res;
        int num_row = board.size();
        // if (!num_row) return res;
        int num_col = board[0].size();

        //点击坐标
        int cl_row = click[0];  
        int cl_col = click[1];

        //如果是M
        if (board[cl_row][cl_col] == 'M')
        {
            board[cl_row][cl_col] = 'X';
            return board;
        }
        
        //是E，dfs遍历修改
        dfs(board, cl_row, cl_col);

        return board;     
    }

    void dfs(vector<vector<char>>& board, int x, int y)
    {
        //统计周边地雷个数
        int cnt = 0;
        for (int i = 0; i < 8; ++i)
        {
            int tx = x + offset_x[i];
            int ty = y + offset_y[i];
            //越界处理
            if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size())
                continue;
            if (board[tx][ty] == 'M')
                cnt++;
        }


        if (cnt > 0)
        {
            board[x][y] = cnt + '0';    //数字
        }
        else
        {
            board[x][y] = 'B';          //B
            //向周边递归遍历
            for (int i = 0; i < 8; ++i)
            {
                int tx = x + offset_x[i];
                int ty = y + offset_y[i];
                //递归终止条件
                if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size() || board[tx][ty] != 'E')
                    continue;       

                dfs(board, tx, ty);
            }
        }
    }

};