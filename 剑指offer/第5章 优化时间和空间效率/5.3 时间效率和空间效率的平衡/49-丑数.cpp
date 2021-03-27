/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 49-丑数.cpp
*   Author      : huihui571
*   Created date: 2020-12-30
*   Description : 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
*   输入: n = 10
*   输出: 12
*   解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
* 说明：1 是丑数。n 不超过1690。
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
 * 以空间换时间
 * 第n个丑数，一定是由之前的某个丑数乘2，3，5得到的，这就是状态转移
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        int two = 0, three = 0, five = 0;
        vector<int> dp(n);
        dp[0] = 1;      //初始化

        for (int i = 1; i < n; ++i) {
            int num2 = dp[two] * 2, num3 = dp[three] * 3, num5 = dp[five] * 5;
            dp[i] = min(min(num2, num3), num5);

            //这里用可能不止一个if被执行，起到去重的作用。比如6=2*3/3*2
            if (dp[i] == num2) two++;
            if (dp[i] == num3) three++;
            if (dp[i] == num5) five++;
        }

        return dp[n - 1];
    }
};
