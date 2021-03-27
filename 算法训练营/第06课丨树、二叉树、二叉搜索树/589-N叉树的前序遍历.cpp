/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 589-N叉树的前序遍历.cpp
*   Author      : huihui571
*   Created date: 2020-07-27
*   Description : 给定一个 N 叉树，返回其节点值的前序遍历。
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

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

#if 0
/**
 * DFS，为保证几个子节点之间访问顺序从左到右，需要把栈中元素反转一下,因为栈将原本的顺序逆转了。
 */
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*> st;

        if (root == NULL)
            return res;

        st.push(root);                      //根入栈
        while (!st.empty())
        {
            Node* cur = st.top();           //出栈，访问之
            st.pop(); 
            res.push_back(cur->val); 
            reverse(cur->children.begin(), cur->children.end()); //反转子节点顺序            
            for (Node* ch : cur->children)  //子节点依次入栈
            {
                if (ch != NULL)
                    st.push(ch);
            }
        }
        
        return res;          
    }
};
#endif

#if 1
/**
 * 递归法
 */
class Solution
{
public:
    vector<int> preorder(Node* root)
    {
        vector<int> res;

        pre_orderN(root, res);
        return res;        
    }

    //N叉树前序递归遍历
    void pre_orderN(Node* root, vector<int>& path)
    {
        if (root == NULL)
            return;

        path.push_back(root->val);
        for (Node* ch : root->children)
        {
            pre_orderN(ch, path);
        } 
    }
};
#endif