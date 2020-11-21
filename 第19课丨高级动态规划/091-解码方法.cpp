/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 091-解码方法.cpp
*   Author      : huihui571
*   Created date: 2020-11-12
*   Description : 一条包含字母 A-Z 的消息通过以下方式进行了编码：
'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。
题目数据保证答案肯定是一个 32 位的整数。
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
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
 * 这题就是要分的情况太多，容易乱。但是本质是看最后一位是能单独译码，还是和前一位结合译码。
 * 若单独译，那dp[i] = dp[i - 1]，不增加情况
 * 若结合译，那dp[i] = dp[i - 2]，相当于前一位单独译，两位合并成一位
 * 注意0的情况，单0和10、20这种情况的区别要考虑到。
 * 小技巧：用到dp[n-2]所以dp[n + 1]，dp[i]对应s[i-1]
 */
class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.empty() || s[0] == '0')
            return 0;

        int n = s.length();
        vector<int> dp(n + 1);
        dp[0] = 1;  //理解为dp[-1] = 1
        dp[1] = 1;

        if (s.length() == 1) return dp[1];
        for (int i = 2; i <= n; ++i)
        {   //当前位为0
            if (s[i - 1] == '0')
            {
                //当前位可以和前面结合成10，20，只能合并译码
                if (s[i - 2] == '1' || s[i - 2] == '2') 
                {
                    dp[i] = dp[i - 2];  
                }
                //出现单0，没法译 
                else
                {
                    return 0;               
                }
            }
            //当前位非0且可以和前面结合成11~19,21~26
            else if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) 
            {
                //这种情况最后一位和前一位可分可合，最终情况是这两种情况的和
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            //当前位非0且前面不是1,2，不能结合只能单独译码
            else
                dp[i] = dp[i - 1];
        }

        return dp[n];
    }
};