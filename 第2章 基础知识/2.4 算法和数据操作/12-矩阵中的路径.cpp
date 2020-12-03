/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 12-矩阵中的路径.cpp
*   Author      : huihui571
*   Created date: 2020-11-30
*   Description : 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
*   路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，
*   那么该路径不能再次进入该格子。
*   例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。
    [["a","b","c","e"],
    ["s","f","c","s"],
    ["a","d","e","e"]]
*   但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
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
 * 回溯法
 */
class Solution {
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0 || word.empty())
            return false;

        int m = board.size(), n = board[0].size();
        // bool* visited = new bool[m * n];    //必须动态分配，否则用vector，然后还要memset初始化
        vector<bool> visited(m * n, false);

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (back_track(board, word, i, j, visited, 0)) {
                    return true;
                }
            }
        }

        // delete[] visited;
        return false;
    }

#if 0
    //回溯算法，if-do版本
    bool back_track(vector<vector<char>>& board, const string& word, int row, int col, vector<bool>& visited, int step) {
        //找到结果
        if (step == word.length())
            return true;

        //如果当前节点合法，访问它，并下探
        bool has_path = false;
        if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size()
            && board[row][col] == word[step] 
            && !visited[row * board[0].size() + col]) {

            visited[row * board[0].size() + col] = true;    //置访问标记

            //做选择，4个方向
            for (int i = 0; i < 4; ++i)
            {
                int new_r = dx[i] + row;
                int new_c = dy[i] + col;
                has_path = has_path || back_track(board, word, new_r, new_c, visited, step + 1);
            }

            //如果从这个节点出发4个方向都不能找到结果，撤销选择
            if (!has_path) {
                visited[row * board[0].size() + col] = false;       
            }
        }

        return has_path;
    }
#endif
#if 1
    //回溯算法，if-not-continue版本
    bool back_track(vector<vector<char>>& board, const string& word, int row, int col, vector<bool>& visited, int step) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return false;
        if (board[row][col] != word[step] || visited[row * board[0].size() + col])
            return false;

        //找到结果
        if (step == word.length() - 1)
            return true;
        
        visited[row * board[0].size() + col] = true;    //置访问标记

        //做选择，4个方向
        bool has_path = false;
        for (int i = 0; i < 4; ++i)
        {
            int new_r = dx[i] + row;
            int new_c = dy[i] + col;
            has_path = has_path || back_track(board, word, new_r, new_c, visited, step + 1);
        }
        
        //撤销选择
        if (!has_path) {
            visited[row * board[0].size() + col] = false;       
        }

        return has_path;
    }
#endif
};