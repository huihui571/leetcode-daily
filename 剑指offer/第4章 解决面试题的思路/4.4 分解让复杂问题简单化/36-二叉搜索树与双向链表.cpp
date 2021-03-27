/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 36-二叉搜索树与双向链表.cpp
*   Author      : huihui571
*   Created date: 2020-12-15
*   Description : 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
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

using namespace std;

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

/**
 * 中序遍历模板
 * 由于是二叉搜索树，考虑在中序遍历的过程中进行操作。对于当前节点来说，假设其左子树已经在递归函数中转换完毕，返回一个tail指针
 * 表示当前已转换完毕的链表尾节点，将当前节点挂在tail节点的后面，并将当前节点设置为新的tail节点，然后在递归去转换右子树。
 * NOTE:1.链表的head怎么确定，head是中序遍历访问的第一个节点，要根据特点设法找到这一个节点，可以设置一个flag或者判断当tail为空时.
 * NOTE:2.中序遍历结束后记得为整个链表的head和tail节点设置指针
 */
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL)
            return NULL;
        Node* head = NULL;  //定义链表的头指针
        Node* tail = NULL;  //尾指针

        inOrder(root, head, tail);      //中序遍历去构造

        //补上头尾之间的连接
        head->left = tail;
        tail->right = head;

        return head;
    }

    //这种把head和tail当参数的写法必须传引用，否则是指针的复制而不是同一个指针，复制的话函数里操作的指针就都是局部变量，出来就丢失了
    //另一种方法是将其定义为全局变量
    void inOrder(Node* root, Node* &head, Node* &tail) {
        if (root == NULL)
            return;

        inOrder(root->left, head, tail);        //左

        if (tail == NULL)   {               //tail还没有被设置，说明是第一次回溯，也就是访问到左下角叶子节点，就是head
            head = root;
        }
        else {
            tail->right = root;             //把当前节点挂在之前转换得到的链表尾节点后面
            root->left = tail;
        }
        tail = root;                        //将当前节点设为新的尾节点

        inOrder(root->right, head, tail);       //右
    }
};
