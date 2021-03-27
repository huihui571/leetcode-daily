/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 43-1～n整数中1出现的次数.cpp
*   Author      : huihui571
*   Created date: 2020-12-27
*   Description : 输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
*   例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次
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
 * 数位DP
 * dp[pos][num1]表示在pos位置，1的出现次数为num1
 * 像密码锁一样，一位一位分层递归，每一层是一个10叉或n(n<10)叉树，在递归函数中只需要统计当前层这一位里1的数量就行了。使用备忘录避免重复计算。
 */
class Solution {
private:
    int digit[20]={0};
    int dp[20][20];
public:
    int countDigitOne(int n) {
        if (n<=0) return 0;
        return solve(n);
    }

    int dfs(int pos, int num1, bool limit){
        if (pos == -1) return num1;

        if (!limit && dp[pos][num1] != -1) return dp[pos][num1];

        int up = limit ? digit[pos] : 9;
        int res = 0;
        for ( int i = 0 ; i <= up ; i++){           //做选择，当前位有up+1种选择
            res += dfs(pos-1,num1 + (i==1),limit && i == up);
        }

        if (!limit) dp[pos][num1] = res;    //当前位有限制的话，方案数肯定和没限制不一样，所以不能重复使用
        return res;
    }

    int solve(int x){
        memset(dp,-1,sizeof(dp));
        int pos = 0;
        while (x){
            digit[pos++] = x%10;
            x/=10;
        }
        return dfs(pos - 1,0,true);
    }
};