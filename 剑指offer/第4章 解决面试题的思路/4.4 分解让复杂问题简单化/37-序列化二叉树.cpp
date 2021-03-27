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

#if 0
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
#endif

 #if 1
/**
 *  bfs + stream
 *  序列化用空格分割，以便反序列化时使用stream
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty()) {
            int q_size = Q.size();
            for (int i = 0; i < q_size; ++i) {
                TreeNode* cur = Q.front();
                Q.pop();
                if (cur == NULL) {
                    res += "# ";
                }
                else {
                    res += to_string(cur->val) + " ";
                    Q.push(cur->left);
                    Q.push(cur->right); 
                }
            }
        }
        res.pop_back();     //最后多一个空格

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return NULL;
        }
        istringstream is(data);
        string str;
        vector<TreeNode*> res; // res 用来将字符串里每个元素转成 TreeNode* 形式的元素
        while(is >> str){
            if(str == "#"){
                res.push_back(NULL);
            }
            else{
                res.push_back(new TreeNode(stoi(str)));
            }
        }

        // 本循环将 res 中的所有元素连起来，变成一棵二叉树
        int pos = 1;
        for(int i = 0; pos < res.size(); ++i){
            if(!res[i]){
                continue;
            }
            res[i]->left = res[pos++]; // pos 此时指向左子树，++后指向右子树
            if(pos < res.size()){
                res[i]->right = res[pos++]; // pos 此时指向右子树，++后指向下一个节点的左子树
            }
        }
        return res[0];
    }
};
#endif

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
