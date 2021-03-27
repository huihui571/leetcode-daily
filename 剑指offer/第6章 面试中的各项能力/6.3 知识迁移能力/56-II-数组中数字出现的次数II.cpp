/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 56-II-数组中数字出现的次数II.cpp
*   Author      : huihui571
*   Created date: 2021-01-03
*   Description : 在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
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
 * 1. 排序。时间复杂度O(nlogn)
 * 2. 哈希表。空间复杂度O(n)
 * 3. 位运算。时间复杂度O(n)，空间复杂度O(1)
 * 考虑数字的二进制形式，对于出现m次的数字，各二进制位出现次数之和都是m的倍数。因此，统计所有数字中各二进制位中1的出现次数，
 * 并对m求余，结果为只出现一次的数字。
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int count[32] = {0};
        //统计各二进制位1的出现次数
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                count[i] += num & 0x01;
                num >>= 1;
            }
        }
        //count各元素对3取余，结果为“只出现一次的数字”的各二进制位
        for (int i = 0; i < 32; ++i) {
            count[i] %= 3;
        }
        //将各二进制位恢复到res上
        for (int i = 0; i < 31; ++i) {
            res |= count[31 - i];   //注意count中的字节序
            res <<= 1;
        }
        res |= count[0];    //最后一位，放到循环里会导致多<<一次
        return res;
    }
};