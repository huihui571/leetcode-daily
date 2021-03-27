/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 189-旋转数组.cpp
*   Author      : huihui571
*   Created date: 2020-07-14
*   Description : 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
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
 * 先反转整个数组，返回分别反转前k个，和剩余元素，就得到结果。
 * 巧是巧，反正我没观察出来整个规律。。。
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

    //反转数组
    void reverse(vector<int>& nums, int start, int end)
    {
        while (start < end)
        {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;

            start++;
            end--;
        }
    }
};



#if 0
/**
 * 时间复杂度太高，未accept
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        for (int i = 0; i < k; i++)
        {
            int tmp = nums[nums.size() - 1];
            for (int j = nums.size() - 1; j > 0; j--)
            {
                nums[j] = nums[j - 1];
            }
            nums[0] = tmp;
        }

    }
};
#endif

#if 0
/**
 * 未详细理解
 */
class Solution {
    public void rotate(int[] nums, int k) {
       int len  = nums.length;
       k = k % len;
       int count = 0;         // 记录交换位置的次数，n个同学一共需要换n次
        for(int start = 0; count < len; start++) {
            int cur = start;       // 从0位置开始换位子
            int pre = nums[cur];   
            do{
                int next = (cur + k) % len;
                int temp = nums[next];    // 来到角落...
                nums[next] = pre;
                pre = temp;
                cur = next;
                count++;
            }while(start != cur)  ;     // 循环暂停，回到起始位置，角落无人
             
        }   
    }  
}
#endif