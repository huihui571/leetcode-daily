/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 57-II-和为s的连续正数序列.cpp
*   Author      : huihui571
*   Created date: 2021-01-03
*   Description : 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
* 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
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
 * 滑动窗口
 */
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> win;
        int left = 1, right = 2;

        while (left < right && right <= (target + 1) / 2) {
            int sum = (left + right) * (right - left + 1) / 2;      //公式求和，比遍历快

            if (sum == target) {
                win.clear();
                for (int i = left; i <= right; ++i) {
                    win.emplace_back(i);        //Note:c++11新增，不是拷贝而是直接在容器中构造元素，效率更高。
                }
                res.emplace_back(win);
                left++;
            }
            else if (sum < target) {
                right++;
            }
            else {
                left++;
            }
        }

        return res;
    }
};
