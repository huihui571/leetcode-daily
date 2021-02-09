/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 5673-移除石子的最大得分.cpp 
*   Author      : huihui571
*   Created date: 2021-02-22
*   Description : 你正在玩一个单人游戏，面前放置着大小分别为a、b、c的 三堆 石子。
*   每回合你都要从两个 不同的非空堆 中取出一颗石子，并在得分上加 1 分。当存在 两个或更多 的空堆时，游戏停止。
*   给你三个整数 a 、b 和 c ，返回可以得到的 最大分数 。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 模拟法
 * 先排序，然后先用最小的去抵消最大的，让最大的和中间的尽可能接近。如果中间的和最大的已经相等了
 * 最小的一堆还没用完，那就用最小的轮流去抵消中间的和最大的，直到最小的一堆用完。最后，每次取剩下
 * 的两堆直到其中一堆用完。
 */
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int res = 0;
        int arr[3] = {a, b, c};
        sort(arr, arr + 3);
        while (arr[0] > 0 && arr[2] - arr[1] > 0) {
            arr[0]--;
            arr[2]--;
            res++;
        }
        int idx = 0;
        while (arr[0] > 0) {
            if (idx++ % 2 == 0) {
                arr[1]--;
            }
            else {
                arr[2]--;
            }
            arr[0]--;
        }
        res += arr[1];
        return res;
    }
};
