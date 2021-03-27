/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 11-旋转数组的最小数字.cpp
*   Author      : huihui571
*   Created date: 2020-11-28
*   Description : 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
*   输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
*   例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  
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
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
 * 二分查找
 * 比较mid和右端点,如果是没有旋转的，那么应该left<mid<right
 * 如果mid<right，那么区间[mid,right]一定是有序的，转折点在[left,mid]里面；
 * 如果mid>right，那么区间[left,mid]一定是有序的，转折点在[mid+1,right]里面
 */
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int res = 0;
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (numbers[mid] < numbers[right]) {    //右半部分有序，最小值在左边，包括mid
                right = mid;         
            }
            else if (numbers[mid] > numbers[right]) {   //左半部分有序，最小值在右边
                left = mid + 1;   
            }
            else {              //中间和右值相等，那它肯定不是最小值，排除右端点（有重复元素）
                right -= 1;
            }
        }

        return numbers[left];
    }
};
