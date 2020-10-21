/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 208-实现 Trie (前缀树).cpp
*   Author      : huihui571
*   Created date: 2020-10-18
*   Description : 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
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
        Trie* node = this;      //从根节点开始
        for (char c : word) {
            //如果在该字符对应的next域里找不到，则插入
            if (node->next[c - 'a'] == NULL) {
                node->next[c - 'a'] = new Trie();
            }
            //找到了则继续下一层去找下一个字符
            node = node->next[c - 'a'];
        }
        node->is_end = true;  //整个单词插入完成，置标志位
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->next[c - 'a'] == NULL)
                return false;
            node = node->next[c - 'a'];
        }
        // return true; 这样只能证明word可能是某个前缀
        return node->is_end;    //end标志才证明匹配到的是个完整的单词
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            if (node->next[c - 'a'] == NULL)
                return false;
            node = node->next[c - 'a'];
        }
        return true;    //前缀不需要end标志，能都匹配上就行
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */