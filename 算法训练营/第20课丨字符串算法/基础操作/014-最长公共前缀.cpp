/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 014-最长公共前缀.cpp
*   Author      : huihui571
*   Created date: 2020-11-21
*   Description : 编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
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
 * 1. 纵向扫描。依次比较每个字符串的第0，1，2...个字符，若出现不等，则停止
 */
class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty()) return "";

        int len = strs[0].length();

        for (int i = 0; i < len; ++i)       //第i个字符
        {
            char cur = strs[0][i];
            for (int j = 1; j < strs.size(); ++j)   //所有的字符串
            {
                if (i == strs[j].length() || cur != strs[j][i]) //注意length不要越界这里
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0]; //只有一个字符串那就返回它本身
    }
};
#endif

#if 0
/**
 * 2. 横向扫描。先求相邻两个字符串的公共前缀，然后再和第三个字符串求公共前缀，依次类推。
 */
class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];

        string comm = strs[0];
        for (int i = 1; i < strs.size(); ++i)
        {
            comm = two_common_prefix(comm, strs[i]);
            if (comm == "")
                return "";
        }
        
        return comm;
    }

    //和上面纵向比较类似，这是更基础的版本
    string two_common_prefix(const string& str1, const string& str2)
    {
        if (str1.empty() || str2.empty())   //若有一个为空，直接返回空
            return "";

        for (int i = 0; i < str1.length(); i++)
        {
            if (i == str2.length() || str1[i] != str2[i])   //若不相等了或者str2提前结束(str2比str1短)
                return str1.substr(0, i);
        }

        return str1;    //若str1比str2短且前面都匹配了
    }
};
#endif

#if 1
/**
 * 2. 分治法。 和横向扫描类似，但不是顺序扫描而是分而治之。
 */
class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty()) return "";

        return lcp(strs, 0, strs.size() - 1);
    }

    string lcp(vector<string>& strs, int start, int end)
    {
        if (start == end)
            return strs[start];

        //划分子问题，每次问题规模缩小一半
        int mid = (start + end) >> 1;
        string left = lcp(strs, start, mid);
        string right = lcp(strs, mid + 1, end);

        //合并两个子问题的结果
        return two_common_prefix(left, right);
    }

    //和上面纵向比较类似，这是更基础的版本
    string two_common_prefix(const string& str1, const string& str2)
    {
        if (str1.empty() || str2.empty())   //若有一个为空，直接返回空
            return "";

        for (int i = 0; i < str1.length(); i++)
        {
            if (i == str2.length() || str1[i] != str2[i])   //若不相等了或者str2提前结束(str2比str1短)
                return str1.substr(0, i);
        }

        return str1;    //若str1比str2短且前面都匹配了
    }
};
#endif