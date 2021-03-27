/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 21-调整数组顺序使奇数位于偶数前面.cpp
*   Author      : huihui571
*   Created date: 2020-12-06
*   Description : 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

#if 1
/**
 * 1. 双指针法，时间复杂度O(n)，空间复杂度O(1)
 * 2. 辅助数组法，时间复杂度O(n)，空间复杂度O(n)
 * 3. 快慢指针法，对号入座，时间O(n)，空间O(1)
 */
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.empty())
            return {};

        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (left < right && !isEven(nums[left])) {   //如果指向奇数就跳过
                left++;
            }
            while (left < right && isEven(nums[right])) {   //如果指向偶数就跳过
                right--;
            }
            swap(nums, left, right);    //left指向偶数，right指向奇数，交换它们
        }

        return nums;
    }

    //判断val是否为偶数，采用位运算
    bool isEven(int val) {
        return (val & 0x01) == 0;
    }

    void swap(vector<int>& nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
};
#endif

#if 0
/**
 * 对号入座法，link:jz-03-数组中的重复数字,283-移动零
 * 奇数元素的座位应该在数组左半部分从0开始递增，用一个指针记录奇数元素的个数，即它们的“座位”，然后把每个奇数元素放到它的座位上去。
 * 由于采用swap这种方法会破坏偶数元素的相对位置
 */
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.empty())
            return {};

        int j = 0;  //记录下一个奇数元素应该在的位置，即“座位”
        for (int i = 0; i < nums.size(); ++i) {
            if (!isEven(nums[i])) {
                if (i != j)                //避免自己和自己交换
                    swap(nums, i, j);   //把奇数元素i放到它的座位去
                j++;                       //遇到奇数元素j+1
            }
        }

        return nums;
    }

    //判断val是否为偶数，采用位运算
    bool isEven(int val) {
        return (val & 0x01) == 0;
    }

    void swap(vector<int>& nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
};
#endif
