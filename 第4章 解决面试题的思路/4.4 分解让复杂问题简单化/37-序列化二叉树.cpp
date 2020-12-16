/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 37-序列化二叉树.cpp
*   Author      : huihui571
*   Created date: 2020-12-16
*   Description : 请实现两个函数，分别用来序列化和反序列化二叉树。
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

/**
 * 序列化时把空指针也保存下来，就可以记录二叉树的全部信息了。
 *  dfs + stream
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "#";         //空指针用特殊符号#记录
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return dfs(is);
    }

    TreeNode* dfs(istringstream &is) {
        string s;
        is >> s;

        if (s == "#")
            return NULL;
        TreeNode* node = new TreeNode(stoi(s));
        node->left = dfs(is);
        node->right = dfs(is);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
