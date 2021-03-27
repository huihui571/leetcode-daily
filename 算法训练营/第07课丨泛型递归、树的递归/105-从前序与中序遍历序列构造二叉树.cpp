/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 105-从前序与中序遍历序列构造二叉树.cpp
*   Author      : huihui571
*   Created date: 2020-07-29
*   Description : 根据一棵树的前序遍历与中序遍历构造二叉树。
注意:
你可以假设树中没有重复的元素。
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

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    unordered_map<int, int> hash_map;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        //构造哈希表，快速定位节点
        for (int i = 0; i < inorder.size(); ++i)
        {
            hash_map[inorder[i]] = i;
        }
        int len = preorder.size();

        return helper(preorder, inorder, 0, len - 1, 0, len - 1);
    }

    TreeNode* helper(const vector<int>& preorder, const vector<int>& inorder,
                    int pre_start, int pre_end, int in_start, int in_end)
    {
        //终止条件
        if (pre_start > pre_end)        
            return NULL;

        //找到前序中序数组中根节点位置
        int pre_root = pre_start;
        int in_root = hash_map[preorder[pre_root]];

        //构造根节点
        TreeNode* root = new TreeNode(preorder[pre_root]);
        
        //计算左子树长度
        int left_size = in_root - in_start;

        //构造左右子树
        root->left = helper(preorder, inorder, pre_start + 1, pre_start + left_size, in_start, in_root - 1);
        root->right = helper(preorder, inorder, pre_start + left_size + 1, pre_end, in_root + 1, in_end);

        return root;
    }
};