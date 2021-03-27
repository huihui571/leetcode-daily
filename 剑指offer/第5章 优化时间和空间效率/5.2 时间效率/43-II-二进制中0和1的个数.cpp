/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 43-II-二进制中0和1的个数.cpp
*   Author      : huihui571
*   Created date: 2020-12-28
*   Description : 将数字转化为二进制，统计二进制数中0的个数不小于1的数字的个数。
*  (1 ≤ Start < Finish ≤ 2,000,000,000)
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

int digit[65];    //存储二进制的每一位，最多64位
int dp[65][30][30]; //dp[i][j][k]表示到第i位，j为0的个数，k为1的个数

int dfs(int pos, int num0, int num1, bool lead, bool limit) {
    //base case
    if (pos == -1 && num0 >= num1) return 1;   //符合条件的数
    if (pos == -1) return 0;                   //不符合

    if (!limit && !lead && dp[pos][num0][num1] != -1) return dp[pos][num0][num1];

    int up = limit ? digit[pos] : 9;
    int sum = 0;    //当前层的临时结果
    for (int i = 0; i < up; ++i) {
//        if (lead)
//            sum += dfs(pos - 1, num0, num1 + (i == 1), lead && i == 0, limit && i == up);   //如果是前导0的话，不计数
//        else
//            sum += dfs(pos - 1, num0 + (i == 0), num1 + (i == 1), lead && i == 0, limit && i == up);
        if (lead) {     //前面一位是0
            if (i == 0)     //这一位还是0
                sum += dfs(pos - 1, num0, num1, true, limit && i == up); //第一个1还没有放下，继续往后看
            else
                sum += dfs(pos - 1, num0, num1 + 1, false, limit && i == up); //放下1，作为二进制的初始
        }
        else {
            if (i == 0)
                sum += dfs(pos - 1, num0 + 1, num1, false, limit && i == up);   //放一个0
            else
                sum += dfs(pos - 1, num0, num1 + 1, false, limit && i == up);   //放一个1
        }
    }

    if (!limit) dp[pos][num0][num1] = sum;  //这里可以不用考虑前导0。why?
    return sum;
}

int solve(int k) {
    int pos = 0;
    while (k) {
        digit[pos++] = k & 0x01;
        k >>= 1;
    }
    //从高位往低位递归求解，每次去掉最高位。比如1234，pos一开始指向1.
    return dfs(pos - 1, 0, 0, 1, 1);
}

int main()
{
    int a,b;
    memset(dp,-1,sizeof(dp));
    scanf("%d%d",&a,&b);
    int x=solve(a-1);
    int y=solve(b);
    printf("%d",y-x);
    return 0;
}