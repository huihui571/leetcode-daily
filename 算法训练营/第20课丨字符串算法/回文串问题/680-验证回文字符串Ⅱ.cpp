/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 680-验证回文字符串Ⅱ.cpp
*   Author      : huihui571
*   Created date: 2020-11-22
*   Description : 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
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

#if 0
/**
 * 双指针，当s[i]==s[j]时正常向前走，当不等时尝试去掉s[i]或者s[j]，就是验证子串s[i+1:j]和s[i:j-1]是否是回文
 * 注意因为最多只能删除一个字符，所有这个验证只能做一次，不要写成递归
 */
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int i = 0, j = s.length() - 1;

        while (i < j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                return valid_sub(s, i + 1, j) || valid_sub(s, i, j - 1);   //去掉s[i]或者s[j]，只有一次机会，不是递归
            }
        }

        return true;
    }

    //检查子串是否是回文
    bool valid_sub(string& s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }

        return true;      
    }
};
#endif

#if 1
/**
 * 如果题目变成最多可以删除K次呢？
 * 递归，增加一个变量k记录修改次数
 */
class Solution
{
public:
    bool validPalindrome(string s, int K)
    {

        return valid_sub(s, 0, s.length() - 1, K);
    }

    bool valid_sub(string& s, int left, int right, int k)
    {
        if (k < 0)
            return false;
        else if (left >= right)
            return true;
 

        if (s[left] == s[right])
        {
            return valid_sub(s, left + 1, right - 1, k);
        }
        else
        {
            return valid_sub(s, left + 1, right, k - 1) || valid_sub(s, left, right - 1, k - 1);
        }
    }
};
#endif