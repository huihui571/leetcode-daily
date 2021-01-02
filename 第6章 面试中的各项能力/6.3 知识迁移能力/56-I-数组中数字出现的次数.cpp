/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 56-I-数组中数字出现的次数.cpp
*   Author      : huihui571
*   Created date: 2021-01-02
*   Description : 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
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
 * 参考问题 ：数组中除一个数字a只出现一次外，其他数字都出现两次，求a。
 * 解法 ：XOR异或位运算。由于两个相同的数字异或的结果是0，所以把数组中所有数字异或的结果就是那个唯一只出现一次的数字。
 * 先通过异或找出两个元素的异或结果。再根据异或结果的出现为1的位置作为mask，mask的二进制只有1位是1，也就是只看两个元素的该位置。
 * 最后，通过与操作判断该位置是0还是1区分两个元素
 */
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) sum ^= n;    //出现两次的数异或会抵消掉，最终sum是a^b的结果
        int a = 0, b = 0;
        int mask = 0x01;
        while ((mask & sum) == 0) {     //找到sum中最低位的1(这里可以是任一位1)
            mask <<= 1;
        }
        for (int n : nums) {            //根据mask这一位是0或1对所有数组进行分组
            if (n & mask)
                a ^= n;                 //每个组内再异或，最后剩下的就是出现一次的那个
            else
                b ^= n;
        }

        return {a, b};
    }
};
