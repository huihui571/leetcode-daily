/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 015-三数之和.cpp
*   Author      : huihui571
*   Created date: 2020-07-04
*   Description : 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。
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

/**
 * 双指针搜索。
 * 关于双指针：二分查找可以看成一种特殊的双指针法，都是初始化在两端，然后根据这两个位置的值算出一个东西(sum或者mid)，将这个东西与target
 *             相比较，根据比较结果判断应该移动哪个指针。
 */
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());     //双指针要先sort

        for (int k = 0; k < nums.size(); ++k)
        {
            if (nums[k] > 0) break;             //k>0，说明3个数都>0，直接排除
            if (k > 0 && nums[k] == nums[k - 1]) continue;      //注意k也要去重

            /*****双指针模板*****/
            int target = nums[k];
            int i = k + 1;
            int j = nums.size() - 1;
            while (i < j)
            {
                int sum = nums[i] + nums[j];
                if (sum + target == 0)
                {
                    res.push_back(vector<int>{target, nums[i], nums[j]});
                    i++;
                    j--;
                    //去重操作往往放在其它操作后面，以免将有用的结果去掉。而且应该是i和i-1比较，去掉后面那个。
                    while (i < j && nums[i] == nums[i - 1]) { i++;}      //去重。
                    while (i < j && nums[j] == nums[j + 1]) { j--;}      //注意i<j限制
                }
                else if (sum + target < 0)
                {
                    i++;
                }
                else if (sum + target > 0)
                {
                    j--;
                }
            }
        }

        return res;
    }
};