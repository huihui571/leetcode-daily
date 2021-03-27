/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 33-二叉搜索树的后序遍历序列.cpp
*   Author      : huihui571
*   Created date: 2020-12-14
*   Description : 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
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

/**
 * 递归法
 * 在[i, j]的区间中，最后一个节点是根节点，从前面开始找第一个大于它的节点，索引记为m，此时可划分出左右子树[i, m - 1]、[m, j - 1]
 * 左区间全部节点已经小于根节点，遍历判断右区间所有节点是否都大于根节点，然后再递归分别判断左右子树。
 */
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size() - 1);
    }

    bool recur(vector<int>& postorder, int i, int j) {
        if (i >= j)             //节点数<=1，肯定是二叉搜索树
            return true;

        int p = i;
        while (postorder[p] < postorder[j]) {   //找左子树
            p++;
        }
        int m = p;      //记录左右子树分割位置
        while (postorder[p] > postorder[j]) {   //右子树
            p++;
        }

        //p == j则当前树判断正确
        return p == j && recur(postorder, i, m - 1) && recur(postorder, m, j - 1);
    }
};
