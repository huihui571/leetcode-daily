/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 354-俄罗斯套娃信封问题.cpp
*   Author      : huihui571
*   Created date: 2021-03-04
*   Description : 给定一些标记了宽度和高度的信封，宽度和高度以整数对形式(w, h)出现。
*   当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
*   请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
*   说明:
*   不允许旋转信封。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 二维的最长递增子序列问题。参考lc300最长递增子序列。
 * 先对数组的一维（如宽度）升序排序，然后对另一维求最长递增子序列。
 * 对于宽度相同的信封，应该按什么顺序排列？因为宽度相同的只能选择一个，所以按降序排列就把后面比它小的都屏蔽掉了。否则相同宽度的，不同高度之间还可能出现
 * 递增子序列，然而这是不允许的。
 */
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty())
            return 0;
        int n = envelopes.size();

        //先排序，第一维升序，第二维降序。可以避免第一维相同的也被套娃
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] < e2[0] || e1[0] == e2[0] && e1[1] > e2[1];
        });

        vector<int> dp(n, 1);   //初始化为1，因为序列至少包含自身
        for (int i = 1; i < n; ++i) {
            //状态i不是从i-1转移来，而是要遍历前面所有的，去找能形成最长子序列的上一个状态
            for (int j = 0; j < i; ++j) {
                if (envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);  //取最大的
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};