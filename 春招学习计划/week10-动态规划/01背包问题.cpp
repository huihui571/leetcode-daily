/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 01背包问题.cpp
*   Author      : huihui571
*   Created date: 2020-03-27
*   Description : 有一个背包，背包的最大承重为 W，还有 N 个物品，每个物品有两个属性：重量和价值，每个物品只有一件。
*   现在需要选择一些物品装入背包，在不超过背包最大承重的前提下，应该尽量使得装入背包的物品的价值总和最大，求最大价值总和是多少。
*   输入格式：
*       第 1 行只有一个整数，表示背包的最大承重；
*       第 2 行是每个物品重量列表 weights ，使用空格隔开；
*       第 3 行是第 2 行每个物品对应的价值列表 values，使用空格隔开。
*   输出格式：
*       输出一个整数，表示最大价值总和。
*   提示：
*   1 <= W <= 100；
*   1 <= N <= 100；
*   1 <= weights[i] <= 1000​；
*   1 <= values[i] <= 1000。
*
*<FH->***************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int W;
    cin >> W;
    vector<int> weights;
    int t;
    while (cin >> t)
    {
        weights.push_back(t);
        if (cin.get() == '\n')
            break;
    }
    vector<int> values;
    while (cin >> t)
    {
        values.push_back(t);
        if (cin.get() == '\n')
            break;
    }
    int N = weights.size();

    //dp[i][j]表示第i个物品，背包剩余容量为j时，物品的最大价值
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            if (j < weights[i - 1])     //装不下了
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    cout << dp[N][W] << endl;
    return 0;
}