/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 070-爬楼梯.cpp
*   Author      : huihui571
*   Created date: 2020-10-21
*   Description : 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。
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
 * 递归+备忘录，实际上就是所谓的剪枝
 */
class Solution
{
private:
    int* memo;
public:
    int climbStairs(int n)
    {
        if (n < 2)
            return 1;
        memo = new int[n + 1]();    //注意0~n有n+1个状态，memo不要越界了

        return f(n);
    }

    //递归函数
    int f(int n)
    {
        if (n < 2)
            return 1;    
        //如果备忘录里有，直接返回
        if (memo[n] != 0)
            return memo[n];
        int f_n = f(n-1) + f(n-2);
        //更新备忘录
        memo[n] = f_n;
        return f_n;
    }
};