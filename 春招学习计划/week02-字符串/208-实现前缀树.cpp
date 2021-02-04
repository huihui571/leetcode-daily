/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 208-实现前缀树.cpp 
*   Author      : huihui571
*   Created date: 2021-01-28
*   Description : 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    bool is_end;
    Trie* next[26];

public:
    /** Initialize your data structure here. */
    Trie() {
        is_end = false;
        memset(next, 0, sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (const char& c : word) {
            if (node->next[c - 'a'] == NULL) {
                node->next[c - 'a'] = new Trie();
            } 
            node = node->next[c - 'a'];
        } 
        node->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (const char& c : word) {
            if (node->next[c - 'a']) {
                node = node->next[c - 'a'];
            }
            else {
                return false;
            }
        }
        return node->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (const char& c : prefix) {
            if (node->next[c - 'a']) {
                node = node->next[c - 'a'];
            }
            else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
