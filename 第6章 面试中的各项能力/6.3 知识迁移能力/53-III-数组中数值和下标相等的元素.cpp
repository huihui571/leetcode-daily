/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 53-III-数组中数值和下标相等的元素.cpp
*   Author      : huihui571
*   Created date: 2021-01-02
*   Description : 假设一个单调递增的数组里每个元素都是整数并且是唯一的。请找出数组中任意一个数值等于其下标的元素。
* 输入：[-3,-1,1,3,5]
* 输出：3
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

/**
 * 举个例子就能发现：要找的数m左边的元素数值一定都小于其下标，而m右边的元素数值一定都大于其下标，这样就可以用二分法查找m。
 */
int getNumSameAsIdx(vector<int>& nums) {
    if (nums.empty()) return -1;
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = (left + right) >> 1;
        if (nums[mid] == mid) {
            return nums[mid];
        }
        else if (nums[mid] < mid) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}
