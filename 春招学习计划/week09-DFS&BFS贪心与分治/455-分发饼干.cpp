/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 455-分发饼干.cpp
*   Author      : huihui571
*   Created date: 2021-03-23
*   Description : 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
*   对每个孩子 i，都有一个胃口值g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j]。
*   如果 s[j]>= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 贪心
 * 先排序，然后从最小胃口的孩子开始，拿最小的饼干去尝试
 */
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                i++;
                j++;
                res++;
            }
            else {
                j++;
            }
        }

        return res;
    }
};

