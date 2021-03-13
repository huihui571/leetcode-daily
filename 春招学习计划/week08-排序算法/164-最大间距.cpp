/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 164-最大间距.cpp
*   Author      : huihui571
*   Created date: 2021-03-13
*   Description : 给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。
*   如果数组元素个数小于 2，则返回 0。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 这题是想考基数排序和桶排序，不想学了，快排先糊弄一下。
 */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        sort(nums.begin(), nums.end());
        int maxDistance = INT_MIN;

        for (int i = 1; i < nums.size(); ++i) {
            int dis = nums[i] - nums[i - 1];
            maxDistance = max(maxDistance, dis);
        }

        return maxDistance;
    }
};

