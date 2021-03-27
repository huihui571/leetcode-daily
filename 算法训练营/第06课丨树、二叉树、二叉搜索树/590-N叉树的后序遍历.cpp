/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 590-N叉树的后序遍历.cpp
*   Author      : huihui571
*   Created date: 2020-07-27
*   Description : 给定一个 N 叉树，返回其节点值的后序遍历。
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


#if 1
/**
 * DFS得到结果是先根的，所以后序要反转一下结果
 */
class Solution
{
public:
    vector<int> postorder(Node* root)
    {
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
            for (Node* ch : cur->children)  //子节点依次入栈
            {
                if (ch != NULL)
                    st.push(ch);
            }
        }
        
        reverse(res.begin(), res.end());   //反转结果
        return res;        
    }
};
#endif

#if 0
/**
 * 递归法
 */
class Solution
{
public:
    vector<int> postorder(Node* root)
    {
        vector<int> res;

        post_orderN(root, res);
        return res;        
    }

    //N叉树后序递归遍历
    void post_orderN(Node* root, vector<int>& path)
    {
        if (root == NULL)
            return;

        for (Node* ch : root->children)
        {
            post_orderN(ch, path);
        }
        path.push_back(root->val);
    }
};
#endif