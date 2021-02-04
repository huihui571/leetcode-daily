/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 212-单词搜索II.cpp 
*   Author      : huihui571
*   Created date: 2021-01-31
*   Description : 给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。
*   单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * DFS回溯 + 字典树剪枝
 */
struct TrieNode {
    bool is_end;
    TrieNode* next[26];
    TrieNode() {
        is_end = false;
        memset(next, 0, sizeof(next));
    }
};

class Solution {
private:
    static constexpr int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int row = board.size();
        int col = row == 0 ? 0 : board[0].size();
        if (row == 0 || col == 0) {
            return res;
        }

        //Build
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            TrieNode* node = root;
            for (char ch : word) {
                if (node->next[ch - 'a'] == NULL) {
                    node->next[ch - 'a'] = new TrieNode();
                }
                node = node->next[ch - 'a'];
            }
            node->is_end = true;
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                string word;
                dfs(board, i, j, word, res, root);
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& board, int i, int j, string& word, vector<string>& res, TrieNode* root) {
        if (i < 0 || i >= board.size() | j < 0 || j >= board[0].size()) {
            return;
        }

        if (board[i][j] == '#' || root->next[board[i][j] - 'a'] == NULL) {
            return;
        }

        char ch = board[i][j];
        word.push_back(ch);
        board[i][j] = '#';
        root = root->next[ch - 'a'];

        if (root->is_end && find(res.begin(), res.end(), word) == res.end()) {
            res.push_back(word);
        }

        for (int k = 0; k < 4; k++) {
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];
            dfs(board, ni, nj, word, res, root);
        }

        board[i][j] = ch;
        word.pop_back();
    }
};

