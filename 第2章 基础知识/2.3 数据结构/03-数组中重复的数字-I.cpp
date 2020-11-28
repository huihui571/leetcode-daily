/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 03-数组中重复的数字-I.cpp
*   Author      : huihui571
*   Created date: 2020-11-02
*   Description : 找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
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
思路：  1. 哈希表 O(N)
        2. 先排序，再遍历 O(NlogN)
        3. 找座位。数字范围0~n-1，所以每个人应该都可以对号入座，把每个人移到自己的位置上去(swap)
            如果出现冲突，则说明重复。平均O(N)，前面while多了后面的就少了。 link:448题.
*/
#if 0
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int res = -1;
        unordered_map<int, int> hash_map(nums.size());
        for (int n : nums)
        {
            if (!hash_map[n])
                hash_map[n]++;
            else
            {
                res = n;
                break;
            }
                
        }

        return res;
    }
};
#endif

#if 1
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
           while (nums[i] != i)
           {
               if (nums[i] == nums[nums[i]])
                    return nums[i];
               swap(nums, i, nums[i]);
           }
        }
        return -1;
    }

    void swap(vector<int>& nums, int i, int j)
    {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
};
#endif