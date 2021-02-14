/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 5678-袋子里最少数目的球.cpp 
*   Author      : huihui571
*   Created date: 2021-02-14
*   Description : 给你一个整数数组 nums ，其中 nums[i] 表示第 i 个袋子里球的数目。同时给你一个整数 maxOperations 。
*   你可以进行如下操作至多 maxOperations 次：
*       选择任意一个袋子，并将袋子里的球分到 2 个新的袋子中，每个袋子里都有 正整数 个球。
*           比方说，一个袋子里有 5 个球，你可以把它们分到两个新袋子里，分别有 1 个和 4 个球，或者分别有 2 个和 3 个球。
*   你的开销是单个袋子里球数目的 最大值 ，你想要 最小化 开销。
*   请你返回进行上述操作后的最小开销。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 这种最小化最大值或者最大化最小值的问题，都可以用二分查找。lower_bound模型
 */
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = (left + right) >> 1;
            if (!check(nums, maxOperations, mid)) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }

    //检查在最大开销不超过cost的情况下，能否完成操作
    bool check(vector<int>& nums, int maxOperations, int cost) {
        int count = 0;
        for (int num : nums) {
            //把num分到容量为cost的袋子中
            if (num % cost == 0) {
                count += num / cost - 1;
            }
            else {
                count += num / cost;
            }
        }
        return count <= maxOperations;
    }
};
