/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 455-分发饼干.cpp
*   Author      : huihui571
*   Created date: 2020-09-09
*   Description : 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
*   对每个孩子 i ，都有一个胃口值 gi ，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j ，都有一个尺寸 sj 。
*   如果 sj >= gi ，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
注意：
你可以假设胃口值为正。
一个小朋友最多只能拥有一块饼干。
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

class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        int cnt = 0;
        int i = 0;
        int j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (i < s.size() && j < g.size())
        {
            if (s[i] >= g[j])
            {
                i++;
                j++;
                cnt++;
            }
            else
            {
                i++;
            }
        }

        return cnt;
    }
};