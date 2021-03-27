/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 32-III-从上到下打印二叉树-III.cpp
*   Author      : huihui571
*   Created date: 2020-12-14
*   Description : 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推
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

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#if 0
/**
 * 层序遍历，用一个flag控制反转奇数层结果
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;

        bool flag = false;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int q_size = Q.size();
            vector<int> cur_res;            //当前一层的结果
            for (int i = 0; i < q_size; ++i) {
                TreeNode* cur = Q.front();      //出队
                Q.pop();
                cur_res.push_back(cur->val);        //访问
                if (cur->left)                  //左右子节点入队
                    Q.push(cur->left);
                if (cur->right)
                    Q.push(cur->right);
            }
            if (flag) {
                reverse(cur_res.begin(), cur_res.end());    //在奇数层反转结果
                res.push_back(cur_res);
            }
            else {
                res.push_back(cur_res);
            }
            flag = !flag;       //切换方向
        }

        return res;
    }
};
#endif

#if 1
/**
 * 层序遍历+双端队列
 * 偶数层：前出后加，从左到右
 * 奇数层：后出前加，从右到左
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;

        bool flag = false;
        deque<TreeNode*> DQ;
        DQ.push_back(root);
        while (!DQ.empty()) {
            int q_size = DQ.size();
            vector<int> cur_res;
            for (int i = 0; i < q_size; ++i) {
                if (flag) {         //奇数层
                    TreeNode* cur = DQ.back();
                    DQ.pop_back();
                    cur_res.push_back(cur->val);
                    if (cur->right)
                        DQ.push_front(cur->right);
                    if (cur->left)
                        DQ.push_front(cur->left);
                }
                else {              //偶数层
                    TreeNode* cur = DQ.front();
                    DQ.pop_front();
                    cur_res.push_back(cur->val);
                    if (cur->left)
                        DQ.push_back(cur->left);
                    if (cur->right)
                        DQ.push_back(cur->right);
                }
            }
            res.push_back(cur_res);
            flag = !flag;
        }

        return res;
    }
};
#endif