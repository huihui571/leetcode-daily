/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 283-移动零.cpp
*   Author      : huihui571
*   Created date: 2020-06-30
*   Description : 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
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
 * 从非零元素入手，而不是考虑0元素。
 * 直接考虑每一个非零元素应该放的位置，把非零元素位置安排好。然后一个循环在后面补0
 * 思路跟开一个新数组有点像，j记录的是新数组中非零元素的下标，但实际是原地操作。
 * 可以原地操作，是因为0不需要保护(只需要记录个数)，直接覆盖掉就行。
 */
class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                nums[j] = nums[i];   
                j++;            //j刚好记录了非零元素的个数，这样就不用记0的个数了
            }
        }
        //补0
        for (int i = j; i < nums.size(); ++i)
        {
            nums[i] = 0;
        }
    }
};
#if 0
class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int zero_count = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                nums[j] = nums[i];   
                j++;
            }
            else
            {
                zero_count++;
            }
        }
        //补0
        for (int i = 0; i < zero_count; ++i)
        {
            nums[nums.size() - 1 - i] = 0;
        }
    }
};
#endif

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {0, 1, 0};
    solution.moveZeroes(nums);
    return 0;
}