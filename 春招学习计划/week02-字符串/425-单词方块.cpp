/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 425-单词方块.cpp 
*   Author      : huihui571
*   Created date: 2021-01-29
*   Description : 给定一个单词集合 （没有重复），找出其中所有的 单词方块 。
*   一个单词序列形成了一个有效的单词方块的意思是指从第 k 行和第 k 列 (0 ≤ k < max(行数, 列数)) 来看都是相同的字符串。
*   例如，单词序列 ["ball","area","lead","lady"] 形成了一个单词方块，因为每个单词从水平方向看和从竖直方向看都是相同的。
*   注意：
*       单词个数大于等于 1 且不超过 500。
*       所有的单词长度都相同。
*       单词长度大于等于 1 且不超过 5。
*       每个单词只包含小写英文字母 a-z。
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

/**
 * 就是把单词表里的单词一行行地放，主结构是回溯。
 * 因为单词方块是对称的，因此上面的单词确定了之后，下面单词的前缀也确定了。因此在回溯的过程中
 * 需要在单词表里寻找带有某个前缀prefix的单词去进行回溯。
 * 可以用哈希表加速这个查找过程，但更合适的是前缀树Trie。
 */

//定义前缀树节点
struct TrieNode {
    TrieNode* next[26];
    vector<int> indexs; //以当前节点为结尾的前缀的单词索引
    TrieNode() {
        memset(next, 0, sizeof(next));
    }
};
//回溯法 + 前缀树
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        vector<vector<string>> res;

        //build Trie
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            TrieNode* node = root;
            for (char ch : words[i]) {
                if (node->next[ch - 'a'] == NULL) {
                    node->next[ch - 'a'] = new TrieNode();
                }
                node = node->next[ch - 'a'];
                node->indexs.push_back(i);      //包含当前前缀的单词索引
            }
        }
       
        //以每个单词为起点回溯一次
        for (const string& word : words) {
            vector<string> square = {word};
            // cout << square.size() << endl;
            back_track(1, words, square, res, root);
        }
        return res;
    }

    void back_track(int step, vector<string>& words, vector<string>& square, vector<vector<string>>& res, TrieNode* root) {
        // cout << "step: " << step << endl;
        if (step == words[0].size()) {
            res.push_back(square);
            return;
        }
        
        //获取前缀
        string prefix = "";
        for (const string& word : square) {
            prefix.push_back(word[step]);
        }
        // cout << "preifx: " << prefix <<endl;
        //获取带有prefix前缀的单词索引
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->next[ch - 'a'] == NULL) {
                return;
            }
            node = node->next[ch - 'a'];
        }
        
        //回溯
        for (int idx : node->indexs) {
            square.push_back(words[idx]);
            back_track(step + 1, words, square, res, root);
            square.pop_back();
        } 
    }
};
