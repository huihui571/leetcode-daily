/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 648-单词替换.cpp 
*   Author      : huihui571
*   Created date: 2021-01-29
*   Description : 在英语中，我们有一个叫做 词根(root)的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。
*   现在，给定一个由许多词根组成的词典和一个句子。你需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。你需要输出替换之后的句子。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 前缀树
 * 用字典里的单词构建前缀树，然后遍历句子中的单词将其替换为前缀。
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
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string res;

        //build Trie
        TrieNode* root = new TrieNode();
        for (const string& word : dictionary) {
            TrieNode* node = root;
            for (char ch : word) {
                if (node->next[ch - 'a'] == NULL) {
                    node->next[ch - 'a'] = new TrieNode();
                }
                node = node->next[ch - 'a'];
            }
            node->is_end = true;
        }

        vector<string> words;
        string word = "";
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] != ' ') {
                word.push_back(sentence[i]);
            }
            else {
                string new_word = change_word(word, root);      //替换单词
                words.push_back(new_word);
                word.clear();
            }
        }
        words.push_back(change_word(word, root));

        for (const string& word : words) {
            res += word + " ";
        } 
        res.pop_back();

        return res;
    }

    string change_word(string& word, TrieNode* root) {
        string new_word = "";
        //start with prefix
        TrieNode* node = root;
        for (char ch : word) {
            if (node->next[ch - 'a'] == NULL) {
                new_word = word;
                break;
            }
            else {
                node = node->next[ch - 'a'];
                new_word.push_back(ch);
                if (node->is_end)
                    break;
            }
        }
        return new_word;    
    }
};
