/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 5739-最高频元素的频数.cpp 
*   Author      : huihui571
*   Created date: 2021-04-25
*   Description : 元素的 频数 是该元素在一个数组中出现的次数。
*   给你一个整数数组 nums 和一个整数 k 。在一步操作中，你可以选择 nums 的一个下标，并将该下标对应元素的值增加 1 。
*   执行最多 k 次操作后，返回数组中最高频元素的 最大可能频数 。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 先排序。
 * 由于最终这个最高频元素一定是数组中的某一个元素，对于排序后的数组，我们肯定是找比它小的紧邻的元素进行加1，
 * 也就是说，找这样一个区间：最多经过k次操作把这个区间中的所有元素变成区间最右侧的元素，求这个区间的最大长度。
 */
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int res = 1;
        int left = 0, right = 1;
        long sum = 0;    //把区间内所有元素变成最后一个元素需要加1的数量

        while (right < nums.size()) {
            sum += (long)(nums[right] - nums[right - 1]) * (right - left);

            while (sum > k) {
                sum -= (nums[right] - nums[left]);
                left++;
            }

            res = max(res, right - left + 1);

            right++;
        }

        return res;
    }
};
