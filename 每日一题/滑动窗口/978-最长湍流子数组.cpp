/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 978-最长湍流子数组.cpp 
*   Author      : huihui571
*   Created date: 2021-02-08
*   Description : 当 A 的子数组 A[i], A[i+1], ..., A[j] 满足下列条件时，我们称其为湍流子数组：
*       若 i <= k < j，当 k 为奇数时， A[k] > A[k+1]，且当 k 为偶数时，A[k] < A[k+1]；
*       或 若 i <= k < j，当 k 为偶数时，A[k] > A[k+1] ，且当 k 为奇数时， A[k] < A[k+1]。
*   也就是说，如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组。
*   返回 A 的最大湍流子数组的长度。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#if 1
/**
 * 滑动窗口
 */
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ret = 1;
        int left = 0, right = 0;

        while (right < arr.size() - 1) {
            if (left == right) {
                if (arr[right] == arr[right + 1] ) {
                    left++;         //相等元素跳过
                }
                right++;        //重合后只要下一个不相等无论是上升还是下降都可以
            }
            else {
                if (arr[right] > arr[right - 1] && arr[right] > arr[right + 1]
                    || arr[right] < arr[right - 1] && arr[right] < arr[right + 1]) {
                    right++;
                }
                else {
                    left = right;   //right不符合条件那中间这一段都不符合
                }
            }
            ret = max(ret, right - left + 1);
        }

        return ret;
    }
};
#endif
#if 0
/**
 * 2.动态规划，用第二维来区分当前添加的元素是在波峰还是波谷。
 * dp[i][0]表示A[0..i]且A[i]在波峰时最长湍流子数组长度，
 * dp[i][1]表示A[0..i]且A[i]在波谷时最长湍流子数组长度
 * 最终结果在两个维度里对dp取最大值
 */
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 0;
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 1;
        dp[0][1] = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                dp[i][0] = dp[i - 1][1] + 1; //波峰由上一个波谷转移而来
                dp[i][1] = 1;               //另一种情况的长度就为1了，就只有当前一个元素
                res = max(res, dp[i][0]);
            }
            else if (arr[i] < arr[i - 1]) {
                dp[i][1] = dp[i - 1][0] + 1;
                dp[i][0] = 1;
                res = max(res, dp[i][1]);
            }
        }

        return res;
    }
};
#endif
