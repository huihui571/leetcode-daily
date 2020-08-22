/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 169-多数元素.cpp
*   Author      : huihui571
*   Created date: 2020-07-30
*   Description : 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
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


#if 0
/**
 * 1.暴力哈希表，时间复杂度O(n)，空间复杂度O(n)
 * 哈希表中存储每个元素出现次数，一次遍历中同时统计次数和比较次数最大值，返回出现次数最多的元素
 */
class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        int res;
        unordered_map<int, int> hasp_map;
        int max_count = INT_MIN;

        for (int i = 0; i < nums.size(); ++i)
        {
            hasp_map[nums[i]]++;
            if (hasp_map[nums[i]] > max_count)
            {
                max_count = hasp_map[nums[i]];
                res = nums[i];
            }
        }  

        return res;
    }
};
#endif

#if 0
/**
 * 2.分治法
 * 将数组分成左右两部分，分别求出左半部分的众数 a1 以及右半部分的众数 a2，随后在 a1 和 a2 中选出正确的众数。
 */
class Solution {
    int count_in_range(vector<int>& nums, int target, int lo, int hi) {
        int count = 0;
        for (int i = lo; i <= hi; ++i)
            if (nums[i] == target)
                ++count;
        return count;
    }
    int majority_element_rec(vector<int>& nums, int lo, int hi) {
        if (lo == hi)
            return nums[lo];
        int mid = (lo + hi) / 2;
        int left_majority = majority_element_rec(nums, lo, mid);
        int right_majority = majority_element_rec(nums, mid + 1, hi);
        if (count_in_range(nums, left_majority, lo, hi) > (hi - lo + 1) / 2)
            return left_majority;
        if (count_in_range(nums, right_majority, lo, hi) > (hi - lo + 1) / 2)
            return right_majority;
        return -1;
    }
public:
    int majorityElement(vector<int>& nums) {
        return majority_element_rec(nums, 0, nums.size() - 1);
    }
};
#endif


/**
 * 3.排序法
 * 数组排序后，nums[n/2]一定是题目要求的出现次数大于一半的数
 * 时间复杂度O(nlogn)
 */

/**
 * 4.投票算法
 * 候选人(cand_num)初始化为nums[0]，票数count初始化为1。
 * 当遇到与cand_num相同的数，则票数count = count + 1，否则票数count = count - 1。
 * 当票数count为0时，更换候选人，并将票数count重置为1。
 * 遍历完数组后，cand_num即为最终答案。
 */
class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        int cand_num = nums[0];     //初始候选人
        int count = 1;              //自己投自己的一票

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == cand_num)    //后面有人选你
                count++;                //威望+1
            else
            {
                count--;                //选了反对派，威望-1
                if (count == 0)         //威望=0，下台，换人
                {
                    cand_num = nums[i];     
                    count = 1;
                }
            }
        }
        return cand_num;
    }
};