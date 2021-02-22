/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 1423-可获得的最大点数.cpp 
*   Author      : huihui571
*   Created date: 2021-02-06
*   Description : 几张卡牌 排成一行，每张卡牌都有一个对应的点数。点数由整数数组 cardPoints 给出。
*   每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 k 张卡牌。
*   你的点数就是你拿到手中的所有卡牌的点数之和。
*   给你一个整数数组 cardPoints 和整数 k，请你返回可以获得的最大点数。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 因为只能从开头或者末尾拿，所以最后拿到的牌一定是连续的（把数组看成环形的话）
 * 就可以用滑动窗口解决。
 * PS: 求拿出牌的最大点数可以转化为求剩余牌的最小点数，剩余牌是连续的比较好求。
 */
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left = n - k, right = n - 1;
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[left + i];
        }
        
        int maxSum = sum;
        while (left < n) {  //right被%后不方便做判断了
            sum += cardPoints[++right % n] - cardPoints[left++ % n];   //加上右侧新进入窗口元素，减去左侧离开窗口元素
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
