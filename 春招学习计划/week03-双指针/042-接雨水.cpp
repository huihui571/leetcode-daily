/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 042-接雨水.cpp 
*   Author      : huihui571
*   Created date: 2021-02-05
*   Description : 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 双指针解法。
 * 一个格子的雨水取决于它自己的高度和它向左向右看到的最高柱子里较低的一个决定。
 * 暴力思路：如果从每个格子出发向左右分别找它左右最高，时间复杂度将是O(n2)。
 * 动态规划：先遍历两遍数组，预先求出每个位置对应的左右最大值，时间复杂度O(n)，空间复杂度O(n)。
 * 双指针：  两个指针从两侧向中间扫，过程中分别各自维护“当前遍历过柱子”的leftMax和rightMax值。由于leftMax和rightMax
 *           两者中是较小的那个起作用，因此如果：左指针求出的leftMax小于右指针求出来的rightMax，即便中间还有更大的
 *           rightMax也对结果没有影响了。我们就可以计算左指针指向柱子的雨水了。反之亦然。时间复杂度O(n)。
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len < 3) return 0;

        int res = 0;
        int leftMax = height[0], rightMax = height[len - 1];
        int left = 1, right = len - 2;      //头和尾不存雨水，跳过

        while (left <= right) {
            if (leftMax < rightMax) {
                res += leftMax > height[left] ? leftMax - height[left] : 0; //计算雨水
                leftMax = max(leftMax, height[left]);                   //更新leftMax
                left++;                                                 //移动指针
            }
            else {
                res += rightMax > height[right] ? rightMax - height[right] : 0;
                rightMax = max(rightMax, height[right]);
                right--;
            }
        }
        return res;
    }
};
