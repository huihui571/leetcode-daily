/*<FH+>***************************************************************
*   Editor      : VSCode
*   File name   : 5715-还原排列的最少操作步数.cpp
*   Author      : huihui571
*   Created date: 2021-03-28
*   Description : 给你一个偶数 n​​​​​​ ，已知存在一个长度为 n 的排列 perm ，其中 perm[i] == i​（下标 从 0 开始 计数）。
* 一步操作中，你将创建一个新数组 arr ，对于每个 i ：
*   如果 i % 2 == 0 ，那么 arr[i] = perm[i / 2]
*   如果 i % 2 == 1 ，那么 arr[i] = perm[n / 2 + (i - 1) / 2]
* 然后将 arr​​ 赋值​​给 perm 。
* 要想使 perm 回到排列初始值，至少需要执行多少步操作？返回最小的 非零 操作步数。
*
*<FH->***************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 按步骤操作就行，注意更新perm数组
 */
class Solution {
public:
    int reinitializePermutation(int n) {
        int count = 0;
        vector<int> perm(n);
        for (int i = 0; i < n; i++)
        {
            perm[i] = i;
        }
        vector<int> orgin;
        orgin = perm;

        vector<int> arr(n);
        while (1)
        {
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    arr[i] = perm[i / 2];
                }
                else
                {
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                }
            }
            count++;
            if (arr == orgin)
            {
                return count;
            }
            perm = arr;
        }

        return count;
    }
};