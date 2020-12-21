/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 39-数组中出现次数超过一半的数字.cpp
*   Author      : huihui571
*   Created date: 2020-12-21
*   Description : 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
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
 * 1. 排序
 * 2. 哈希表
 * 3. 摩尔投票算法。核心思想是相互抵消，有一个数字出现次数超过数组长度一半，也就是说它的出现次数比剩下所有数字出现次数的和还要多，那么抵消
 * 到最后剩下的一定是这个超过一半的数字。
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
#if 0
        unordered_map<int, int> count;
        int max_count = INT32_MIN;
        int res = 0;
        for (int num : nums) {
            count[num]++;
            if (count[num] > max_count) {
                max_count = count[num];
                res = num;
            }
        }
        //res出现次数最多但不一定大于一半，检查一下
        return count[res] > nums.size() / 2 ? res : 0;
#endif
        if (nums.empty())
            return 0;
        int res = nums[0];      //假设nums[0]是答案
        int times = 1;          //为它设置次数
        for (int i = 1; i < nums.size(); ++i) {
            if (times == 0) {
                res = nums[i];
                times = 1;
            }
            else if (res == nums[i]) {
                times++;
            }
            else {
                times--;
            }
        }

        return res;
    }
};