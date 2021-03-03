/*<FH+>***************************************************************
*   Editor      : VSCode
*   File name   : 001-两数之和.cpp
*   Author      : huihui571
*   Created date: 2021-01-22
*   Description : 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
你可以按任意顺序返回答案。
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
 * 哈希表
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dict;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (dict.count(target - nums[i])) {
                return {i, dict[target - nums[i]]};
            }
            dict[nums[i]] = i;
        }

        return {-1, -1};
    }
};