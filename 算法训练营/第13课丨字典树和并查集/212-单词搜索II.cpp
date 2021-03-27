/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 212-单词搜索II.cpp
*   Author      : huihui571
*   Created date: 2020-10-18
*   Description : 给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
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
#include <string.h>

using namespace std;

struct TrieNode
{
    bool is_end;
    TrieNode* next[26];
    TrieNode()
    {
        is_end = false;
        memset(next, 0, sizeof(next));
    }
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        vector<string> res;
        int row = board.size();
        int col = row ? board[0].size() : 0;
        if (row == 0 || col == 0)
            return res;

        //构建字典树
        TrieNode* root = new TrieNode();
        for (string word : words)
        {
            TrieNode* node = root;  //从根节点开始匹配
            for (char c : word)  //对于每一个字符
            {       
                if (node->next[c - 'a'] == NULL)    //没找到就插入
                    node->next[c - 'a'] = new TrieNode();

                node = node->next[c - 'a'];     //找到了就去下一层找下一个字符
            }
            node->is_end = true;        //结束置单词标志位
        }

        //从棋盘中每个位置开始dfs回溯
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                string word;    //当前路径(单词)
                dfs(board, i, j, root, word, res);
            }
        }
        return res;
    }

    //深度优先搜索
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root, string& word, vector<string>& res)
    {
        //超出界限
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
        
        //该点已访问过或不存在于字典树中
        if (board[i][j] == '@' || root->next[board[i][j] - 'a'] == NULL)
            return;

        char c = board[i][j];
        word.push_back(c);  //做选择
        board[i][j] = '@';  //置访问标志

        root = root->next[c - 'a'];
        if (root->is_end == true && find(res.begin(), res.end(), word) == res.end())   //找到一个在字典树中的不重复的单词
        {
            res.push_back(word);
        }

        dfs(board, i + 1, j, root, word, res);
        dfs(board, i - 1, j, root, word, res);
        dfs(board, i, j + 1, root, word, res);
        dfs(board, i, j - 1, root, word, res);

        board[i][j] = c;    //清除访问标志
        word.pop_back();    //取消选择
    }
};