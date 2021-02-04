/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 069-x的平方根.cpp 
*   Author      : huihui571
*   Created date: 2021-01-23
*   Description : 实现 int sqrt(int x) 函数。计算并返回 x 的平方根，其中 x 是非负整数。
*   由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int left = 1, right = x;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (pow(mid) <= x && pow(mid + 1) > x) {
                return mid;
            }
            else if (pow(mid) > x) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return -1;        
    }

    long pow(int x) {
        return (long)x * (long)x;
    }
};
