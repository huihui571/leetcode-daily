/*<FH+>***************************************************************
 *   Editor     : VSCode
 *   File name   : 486-预测赢家.cpp
 *   Author     : huihui571
 *   Created date: 2021-03-26
 *   Description : 给定一个表示分数的非负整数数组。 玩家 1从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任意一端拿取分数，
 *  然后玩家 1 拿，……。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。
 *  给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。
 *
 *<FH->***************************************************************/
#include <bits/stdc++.h>

using namespace std;

/**
 * dp[i][j]表示作为先手，在区间nums[i..j]里进行选择可以获得的相对分数，即我方得分减去对方得分。最后若dp[0][n-1]大于等于0则先手可以获胜。
 * 玩家1就是这里的先手。
 * 这种两方博弈的问题，是区间动态规划的典型问题。
 */
class Solution
{
public:
    bool PredictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = nums[i]; //只有一个元素时只能选这个元素
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++)
            {
                //若选择i，则自己得分为nums[i]，对方只能在nums[i+1..j]里选，得分为dp[i+1][j]
                //若选择j，则自己得分为nums[j]，对方只能在nums[i..j-1]里选，得分为dp[i][j-1]
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);   
            }
        }

        return dp[0][n - 1] >= 0;
    }
};