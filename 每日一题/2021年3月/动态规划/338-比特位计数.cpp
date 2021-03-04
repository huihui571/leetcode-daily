/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 338-比特位计数.cpp 
*   Author      : huihui571
*   Created date: 2021-03-03
*   Description : 给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * i >> 1会把最低位去掉，如果最低位是0那么dp[i]=dp[i>>1]，如果最低位是1那么dp[i]=dp[i>>1]+1
 * 也可以看作是分奇偶，偶数和n/2个数相同，奇数等于n/2个数加1.
 */
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1);
        for (int i = 0; i <= num; i++) {
            if ((i & 0x01) == 0) {
                dp[i] = dp[i >> 1];
            }
            else {
                dp[i] = dp[i >> 1] + 1;
            }
        }
        return dp;
    }
};
