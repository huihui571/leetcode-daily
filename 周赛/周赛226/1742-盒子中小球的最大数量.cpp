/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 1742-盒子中小球的最大数量.cpp 
*   Author      : huihui571
*   Created date: 2021-01-31
*   Description : 你在一家生产小球的玩具厂工作，有 n 个小球，编号从 lowLimit 开始，到 highLimit 结束（包括 lowLimit 和 highLimit ，即 n == highLimit - lowLimit + 1）。另有无限数量的盒子，编号从 1 到 infinity 。
*   你的工作是将每个小球放入盒子中，其中盒子的编号应当等于小球编号上每位数字的和。例如，编号 321 的小球应当放入编号 3 + 2 + 1 = 6 的盒子，而编号 10 的小球应当放入编号 1 + 0 = 1 的盒子。
*   给你两个整数 lowLimit 和 highLimit ，返回放有最多小球的盒子中的小球数量。如果有多个盒子都满足放有最多小球，只需返回其中任一盒子的小球数量。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> dict;
        for (int i = lowLimit; i <= highLimit; i++) {
            int sum = bitSum(i);
            dict[sum]++;
        }
        int max_sum = INT_MIN;
        for (const auto& d : dict) {
            max_sum = max(max_sum, d.second);
        }
        return max_sum;
    }
    
    int bitSum(int n) {
        int sum = 0;
        int a  = 0;
        while (n) {
            a = n % 10;
            n /= 10;
            sum += a;
        }
        return sum;
    }
};
