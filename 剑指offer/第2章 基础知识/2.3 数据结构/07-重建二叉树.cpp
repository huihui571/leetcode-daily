/*<FH+>***************************************************************
*   Editor      : Visual Studio 2019
*   File name   : 07-重建二叉树.cpp
*   Author      : huihui571
*   Created date: 2020-11-24
*   Description : 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 递归建立，把握一根一区间
 * 一根：当前子树根节点root_pre(前序数组里)； 一区间：当前子树元素开始和结束区间[start,end](中序数组里)
 * 1. 找到前序这个根在中序数组里的位置，root_pre --> root (哈希表)
 * 2. 在中序数组里划分左右子树，左子树:[start, root - 1]; 右子树:[root + 1, end]
 * 3. 更新根节点位置，左子树:root_pre + 1; 右子树:root_pre + (root - start) + 1
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return NULL;
        
        unordered_map<int, int> index_map;      //存储前序中每个节点在中序数组中的位置  
        for (int i = 0; i < inorder.size(); ++i)
        {
            index_map[inorder[i]] = i;    
        }

        TreeNode* root = BuildSubTree(preorder, inorder, 0, 0, inorder.size() - 1, index_map);

        return root;
    }

    //root_pre前序，start end中序
    TreeNode* BuildSubTree(vector<int>& preorder, vector<int>& inorder, int root_pre, int start, int end, unordered_map<int, int>& index_map) {
        if (start > end)       
            return NULL;
            
        TreeNode* node = new TreeNode(preorder[root_pre]);        //new一个根节点
        int root = index_map[preorder[root_pre]];             //计算根节点在中序数组中的位置

        //为root节点递归建立左右子树
        node->left  = BuildSubTree(preorder, inorder, root_pre + 1,               start, root - 1,  index_map);
        node->right = BuildSubTree(preorder, inorder, root_pre + (root - start) + 1, root + 1, end, index_map);

        return node;
    }
};