/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 211-添加与搜索单词.cpp 
*   Author      : huihui571
*   Created date: 2021-01-30
*   Description : 请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。
*   实现词典类 WordDictionary ：
*   WordDictionary() 初始化词典对象
*   void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
*   bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 数据结构设计--字典树
 */
class WordDictionary {
private:
    struct TrieNode {
        bool is_end;
        TrieNode* next[26];     
        TrieNode() {
            is_end = false;
            memset(next, 0, sizeof(next));
        }
    };
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode(); 
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->next[ch - 'a'] == NULL) {
                node->next[ch - 'a'] = new TrieNode();
            }
            node = node->next[ch - 'a'];
        }
        node->is_end = true;
    }

    bool search(string word) {
        return search_help(word, root);
    }
    bool search_help(string word, TrieNode* root) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            //对于通配符，递归去查找
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (node->next[j]) {
                        if (search_help(word.substr(i + 1), node->next[j]))
                            return true;
                    }
                }
                return false;
            }
            else if (node->next[word[i] - 'a'] == NULL){
                return false;
            }
            node = node->next[word[i] - 'a'];
        }
        return node->is_end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_3 = obj->search(word);
 */

