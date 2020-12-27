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

    int dfs(int pos, int cnt, bool limit){
        if (pos == 0) return cnt;
        if (!limit && dp[pos][cnt] != -1) return dp[pos][cnt];
        int up = limit ? digit[pos] : 9;
        int res = 0;

        for ( int i = 0 ; i <= up ; i++){
            res += dfs(pos-1,cnt + (i==1),limit && i == up);
        }

        if (!limit) dp[pos][cnt] = res;
        return res;
    }

    int solve(int x){
        memset(dp,-1,sizeof(dp));
        int len = 0;
        while (x){
            digit[++len] = x%10;
            x/=10;
        }
        return dfs(len,0,true);

    }
};