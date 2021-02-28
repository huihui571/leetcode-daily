/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : jz36-二叉搜索树与双向链表.cpp 
*   Author      : huihui571
*   Created date: 2021-02-27
*   Description : 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
*   要求不能创建任何新的节点，只能调整树中节点指针的指向。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
private:
    Node* head = NULL;
    Node* pre = NULL;
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL)
            return NULL;
        
        inorder(root);
        //处理循环。pre现在指向链表最后一个节点
        pre->right = head;
        head->left = pre;

        return head;
    }

    void inorder(Node* cur) {
        if (cur == NULL)
            return;
        
        inorder(cur->left);
        if (pre == NULL)
            head = cur;     //处理头节点
        else
            pre->right = cur;
        cur->left = pre;
        pre = cur;          //更新pre
        inorder(cur->right);
    }
};
