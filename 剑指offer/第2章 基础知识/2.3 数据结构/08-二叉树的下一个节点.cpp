/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 08-二叉树的下一个节点.cpp
*   Author      : huihui571
*   Created date: 2020-11-28
*   Description : 给定一棵二叉树和其中的一个节点，如何找出中序遍历序列的下一个节点？
*   树中的节点除了有两个分别指向左、右字节点的指针，还有一个指向父节点的指针。
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
#include <unordered_set>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) , parent(nullptr){}
};

/**
 * 画一个图帮助分析，通过具体例子找出下一节点的规律
 */
class Solution {
public:
    TreeNode* getNext(TreeNode* node) {
        if (node == nullptr)
            return nullptr;

        TreeNode* next = nullptr;
        //最简单的情况，右子树不为空
        if (node->right != nullptr) {
            TreeNode* p = node->right;
            while (p->left != nullptr) {
                p = p->left;
            }
            next = p;
        }
        //没有右子树，如果自己本身是左字节点，那么其父节点就是答案; 
        //如果自己本身是右子节点，那就要一直向上找，找到是左子分支的节点，那么那个节点的父节点就是答案。
        else if (node->parent != nullptr) {
            TreeNode* cur = node;
            TreeNode* par = node->parent;
            
            while (par != nullptr && cur == par->right) {
                cur = par;
                par = par->parent;
            }

            next = par;
        }

        return next;
    }
};