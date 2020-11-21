/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 338-比特位计数.cpp
*   Author      : huihui571
*   Created date: 2020-11-01
*   Description : 给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。
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

#if 0
/**
 * 逐个计算，时间复杂度O(N*sizeof(i))
 */
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> res(num + 1);
        for (int i = 0; i <= num; ++i)
        {
            res[i] = hammingWeight(i); 
        }

        return res;
    }
    //计算数字中位1的个数，即汉明weight
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n != 0)
        {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};
#endif

/**
 * 动态规划法
 * k = i & (i - 1) 是把i的最低一个1置0，则i和k之间只差最后一个1不同
 * dp[i] = dp[k] + 1;
 */
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> dp(num + 1);
        dp[0] = 0;
        for (int i = 1; i <= num; ++i)
        {
            dp[i] = dp[i & (i - 1)] + 1; 
        }

        return dp;
    }
};