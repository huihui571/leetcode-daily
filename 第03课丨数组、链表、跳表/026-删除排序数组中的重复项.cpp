/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 026-删除排序数组中的重复项.cpp
*   Author      : huihui571
*   Created date: 2020-07-14
*   Description : 给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
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
 * 双指针，其实类似链表去重中新建一个链表的方式。
 * 把i看成是新数组的下标，j在原数组中遍历选择合适的元素插入i中。
 * 注意有序数组才能用双指针(因为重复的一定相邻)，否则只能两个for遍历。
 */
class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int length = 0;
        if (nums.empty())
            return length;

        int i = 0;
        for (int j = 1; j < nums.size(); ++j)   //从1开始遍历原链表
        {
            if (nums[i] != nums[j])     //如果不等
            {
                nums[++i] = nums[j];    //插入i+1处
            }
        }

        length = i + 1;
        return length;
    }
};

#if 0
/**
 * 双指针。前指针i，后指针j，比较i和j元素是否相等，相等则j后移；如果不等复制a[j]到a[i+1]，然后i，j后移。
 */
class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        int i=0;
        for (int j = 1; j < nums.size(); ++j)
        {
            while (j < nums.size() && nums[i] == nums[j])  //找到下一个不重复元素
            {
                j++;
            }
            if (j != nums.size())   //走到尽头没有找到下一个不重复元素，则i不动
            {
                nums[i+1] = nums[j];        //替换
                i++;
            }      
        }

        int length = i + 1;     //长度等于下标加一
        return length;
    }
};
#endif