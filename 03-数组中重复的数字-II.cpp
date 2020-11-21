/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 03-数组中重复的数字-II.cpp
*   Author      : huihui571
*   Created date: 2020-11-03
*   Description : 不修改找出数组中重复的数字。
*   在长度为n+1的数组里所有的数字都在1~n的范围内，所以数组中至少有一个数字是重复的。
*   请找出任一个重复的数字，但不能修改输入的数组。
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
思路：   1. 哈希表可以 O(N)
        2. new一个新数组，向新数组赋值的时候直接把每个元素放入对应位置，若冲突则找到重复。
        3. 类似二分法，因为输入的数字范围是1~n，它被中间值m分为1~m和m~n两部分。遍历整个数组，
        如果找到1~m的数字个数超过m，那么重复数字一定在这一半区间里，否则，在m+1~n区间里。
*/

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<int> nums2(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums2[nums[i]] != nums[i])
                nums2[nums[i]] = nums[i];
            else
                return nums[i];
        }
        return -1;
    }
};