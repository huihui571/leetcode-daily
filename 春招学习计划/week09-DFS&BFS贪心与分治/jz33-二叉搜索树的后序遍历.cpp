/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : jz33-二叉搜索树的后序遍历.cpp
*   Author      : huihui571
*   Created date: 2021-03-23
*   Description : 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 最后一个元素是根节点，关键是找到哪些是左子树哪些是右子树。
 * 从头开始找第一个大于根节点的元素m，那么前面走过的[l,m-1]是左子树，[m, r-1]是右子树，如果左子树全小于根节点，右子树全大于根节点就符合，然后
 * 递归判断左右子树的序列。
 */
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return vefiry(postorder, 0, postorder.size() - 1);
    }

    bool vefiry(vector<int>& postorder, int left, int right) {
        if (left >= right)
            return true;
        int root = postorder[right];
        int i = left;
        while (i < right && postorder[i] < root) {
            i++;
        }
        int mid = i;
        while (postorder[i] > root) {
            i++;
        }

        return i == right && vefiry(postorder, left, mid - 1) && vefiry(postorder, mid, right - 1);
    }
};

