/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 数组中数字出现的次数-II.cpp
*   Author      : huihui571
*   Created date: 2021-03-04
*   Description : 在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
*
*<FH->************************************************************************/
<bits/stdc++.h>
#include using namespace std;

/**
 * 位运算。考虑每一个bit中‘0’或‘1’出现的次数。
 * 出现3次的数对该位中1的贡献次数是3，那么所有出现3次的数对该位中1的贡献一定是3的倍数。
 * 所以统计该位中1出现的次数，然后对3取余，就是只出现一次那个数对该位的贡献，即该位是0还是1。
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = {0}; //局部变量要初始化
        //统计
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                count[i] += num & 0x01;
                num >>= 1;
            }
        }
        //对3取余
        for (int i = 0; i < 32; ++i) {
            count[i] = count[i] % 3;
        }
        //还原只出现一次的数
        int res = 0;
        for (int i = 0; i < 31; ++i) {
            res |= count[31 - i];
            res <<= 1;
        }
        res |= count[0];
        return res;
    }
};

