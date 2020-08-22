/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 236-二叉树的最近公共祖先.cpp
*   Author      : huihui571
*   Created date: 2020-07-28
*   Description : 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
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

/**
 * 回溯法，自底向上，所以找到的第一个公共祖先就是最近公共祖先。
 * 1.终止条件：
 *   1.当越过叶节点，则直接返回 nullnull ；
 *   2.当 rootroot 等于 p, qp,q ，则直接返回 rootroot ；
 * 2.递推工作：
 *   1.开启递归左子节点，返回值记为 leftleft ；
 *   2.开启递归右子节点，返回值记为 rightright ；
 *3.返回值： 根据 leftleft 和 rightright ，可展开为四种情况；
 *   1.当 leftleft 和 rightright 同时为空 ：说明 rootroot 的左 / 右子树中都不包含 p,qp,q ，返回 nullnull ；
 *   2.当 leftleft 和 rightright 同时不为空 ：说明 p, qp,q 分列在 rootroot 的 异侧 （分别在 左 / 右子树），因此 rootroot 为最近公共祖先，返回 rootroot ；
 *   3.当 leftleft 为空 ，rightright 不为空 ：p,qp,q 都不在 rootroot 的左子树中，直接返回 rightright 。具体可分为两种情况：
 *      -p,qp,q 其中一个在 rootroot 的 右子树 中，此时 rightright 指向 pp（假设为 pp ）；
 *      -p,qp,q 两节点都在 rootroot 的 右子树 中，此时的 rightright 指向 最近公共祖先节点 ；
 *   4.当 leftleft 不为空 ， rightright 为空 ：与情况 3. 同理；
 * 
 */
class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == NULL)
            return NULL;

        if (root == p || root == q)     //如果当前节点是p或q，那么当前节点就是其祖先
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left == NULL && right == NULL)  
            return NULL;            //两边都不包含p,q
        if (left == NULL)
            return right;           //如果左子树返回为空，说明p,q在右子树里
        if (right == NULL)
            return left;            //如果右子树返回为空，说明p,q在左子树里
        
        return root;            //左右都不为空，说明p,q分别在左右子树,当前根节点就是最近公共祖先
    }

};