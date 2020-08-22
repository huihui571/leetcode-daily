/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 001-两数之和.cpp
*   Author      : huihui571
*   Created date: 2020-06-23
*   Description : 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
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
#include <algorithm>

using namespace std;

#if 1
/**
 * 哈希表法，空间复杂度O(n)，时间复杂度O(n)
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (umap.find(target - nums[i]) != umap.end())
            {
                return vector<int>{umap[target - nums[i]], i};
            }
            else
            {
                umap[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};
#endif

#if 0
/**
 * 双指针搜索法，空间复杂度O(1)，时间复杂度O(n) + O(nlogn) = O(nlogn)
 * 此题要求返回下标而不是值，sort会破坏下标。所以不能用此法，但是思路很经典，可以用于变形。
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        while (i < j)
        {
            int sum = nums[i] + nums[j];
            if (sum == target)
            {
                res = {i, j};
                return res;
            }
            else if (sum < target)
            {
                i++;
            }
            else if (sum > target)
            {
                j--;
            }
        }

        res = {-1, -1};
        return res;
    }
};
#endif