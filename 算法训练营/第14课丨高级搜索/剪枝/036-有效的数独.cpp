/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 036-有效的数独.cpp
*   Author      : huihui571
*   Created date: 2020-10-23
*   Description : 判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
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

#if 0
/**
 * 对于每个位置，扫描行、列、块去判断是否有和当前重复的字符。
 */
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int num_row = board.size();
        int num_col = board[0].size();

        for (int i = 0; i < num_row; ++i)
        {
            for (int j = 0; j < num_col; ++j)
            {
                bool t = isValid(board, i, j);
                if (!t)
                {
                    cout <<  i<< j<< endl;
                    return false;
                }
            }
        }
        return true;
    }

    //验证每个位置
    bool isValid(vector<vector<char>>& board, int i, int j)
    {
        char c = board[i][j];
        if (c == '.')
            return true;

        //因为行、列和块都是有9个，因此可以在一个循环里搞定
        //注意遍历时避开自己!!
        for (int k = 0; k < 9; ++k)
        {
            //检查行
            if (k != j && board[i][k] == c)
                return false;
            //检查列
            if (k != i && board[k][j] == c)
                return false;
            //检查块
            int b_i = (i / 3) * 3 + k / 3;
            int b_j = (j / 3) * 3 + k % 3;
            if ((i != b_i && j != b_j)
                && board[b_i][b_j] == c)
                return false;
        }
        return true;
    }
};
#endif

#if 1
/**
 * 使用哈希表记录行、列、块中每个元素出现次数，而不是每次都遍历。
 */
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {

        int num_row = board.size();
        int num_col = board[0].size();

        vector<unordered_map<char, int>> row_dict(9);  //记录每行中每个数字出现的次数
        vector<unordered_map<char, int>> col_dict(9);
        vector<unordered_map<char, int>> block_dict(9);

        // //初始化哈希表
        // for (int i = 0; i < 9; ++i)
        // {
        //     for (int j = 0; j < 9; ++j)
        //     {
        //         row_dict[i][j + '1'] = 0;
        //     }
        // }

        for (int i = 0; i < num_row; ++i)
        {
            for (int j = 0; j < num_col; ++j)
            {
                if (board[i][j] == '.')
                    continue;
                row_dict[i][board[i][j]] += 1;  //第i行中字符c出现次数加一
                col_dict[j][board[i][j]] += 1; 
                int block_idx = (i / 3) * 3 + j / 3;  //注意这里计算的是block索引而不是元素在block中位置！
                block_dict[block_idx][board[i][j]] += 1; 

                //如果之前已经存在于哈希表中
                if (row_dict[i][board[i][j]] > 1 ||
                    col_dict[j][board[i][j]] > 1 ||
                    block_dict[block_idx][board[i][j]] > 1)
                {
                    return false;
                }
            }
        }
        return true;
    } 
};
#endif