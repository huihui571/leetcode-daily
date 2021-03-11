/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 204-计数质数.cpp 
*   Author      : huihui571
*   Created date: 2021-03-07
*   Description : 统计所有小于非负整数 n 的质数的数量。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 埃氏筛
 * 从小到大遍历每个数，如果这个数为质数，则将其所有的倍数都标记为合数（除了该质数本身）
 */
class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);  //1是质数，0是合数
        //这里可以优化为从2到根号n
        for (int i = 2; i < n; i++) {
            //如果当前是质数
            if (isPrime[i]) {
                //就把从2*i开始，i的所有倍数设置成false
                for (int j = 2 * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        //计数
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                cnt++;
            }
        }

        return cnt;
    }
};
