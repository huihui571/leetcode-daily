/*<FH+>************************************************************************
*   Editor      : vscode
*   File name   : 303-区域和检索-数组不可变.cpp 
*   Author      : huihui571
*   Created date: 2021-03-25
*   Description : 给定一个整数数组  nums，求出数组从索引 i 到 j（i ≤ j）范围内元素的总和，包含 i、j 两点。
*   实现 NumArray 类：
*       NumArray(int[] nums) 使用数组 nums 初始化对象
*       int sumRange(int i, int j) 返回数组 nums 从索引 i 到 j（i ≤ j）范围内元素的总和，包含 i、j 两点（也就是 sum(nums[i], nums[i + 1], ... , nums[j])）
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;
/**
 * 前缀和例题。
 * Note:前缀和其实就是积分，是差分的逆运算。
 */
class NumArray {
private:
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n + 1);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i]; //sums[i]表示前i个数的和
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
