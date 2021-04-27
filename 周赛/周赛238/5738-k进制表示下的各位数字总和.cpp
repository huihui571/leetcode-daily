/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 5738-K进制表示下的各位数字总和.cpp 
*   Author      : huihui571
*   Created date: 2021-04-25
*   Description : 给你一个整数 n（10 进制）和一个基数 k ，请你将 n 从 10 进制表示转换为 k 进制表示，计算并返回转换后各位数字的 总和 。
*   转换后，各位数字应当视作是 10 进制数字，且它们的总和也应当按 10 进制表示返回。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 除K取余法
 */
class Solution {
public:
    int sumBase(int n, int k) {
        vector<int> data;
        while (n) {
            int a = n % k;
            data.push_back(a);
            // cout << a << endl;
            n = n / k;
        }
        
        return bitsum(data);
    }
    
    int bitsum(vector<int> nums) {
        int sum = 0;
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            sum += nums[i];
        }
        
        return sum;
    }
};
