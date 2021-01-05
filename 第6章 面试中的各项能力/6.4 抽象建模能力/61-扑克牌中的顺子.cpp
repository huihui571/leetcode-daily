/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 61-扑克牌中的顺子.cpp
*   Author      : huihui571
*   Created date: 2021-01-05
*   Description : 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
*   2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。
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
 * 先排序再遍历，如果不连续了，用0去填充；如果有重复的元素，那直接返回false.
 */
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zero_nums = 0;

        for (int i = 0; i <nums.size(); ++i) {
            if (nums[i] == 0) {
                zero_nums++;
                continue;
            }

            int j = i + 1;
            if (j < nums.size()) {
                if (nums[j] == nums[i])     //有重复不可能是顺子
                    return false;
                int gap = nums[j] - nums[i];
                while (gap > 1) {
                    if (zero_nums == 0)
                        return false;       //没有0可以填充了
                    zero_nums--;
                    gap--;
                }
            }
        }

        return true;
    }
};