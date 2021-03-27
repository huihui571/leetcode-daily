/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 151-翻转字符串里的单词.cpp
*   Author      : huihui571
*   Created date: 2020-11-21
*   Description : 给定一个字符串，逐个翻转字符串中的每个单词。
说明：
    无空格字符构成一个 单词 。
    输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
    如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
示例 1：
    输入："the sky is blue"
    输出："blue is sky the"
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

#if 0
/**
 * 先整体反转
 * 确定子串的起始位置和结束位置。向前移动，局部反转。
 * 删除末尾多余的空格。
 */
class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());

        int n = s.size();
        int pos = 0;    //结果中每一个单词的末尾位置

        for (int start = 0; start < n; start++)
        {
            if (s[start] != ' ')
            {
                // 填一个空白字符然后将idx移动到下一个单词的开头位置
                if (pos != 0)
                    s[pos++] = ' ';

                // 循环遍历至单词的末尾
                int end = start;
                while (end < n && s[end] != ' ')
                    s[pos++] = s[end++];

                // 反转整个单词
                reverse(s.begin() + pos - (end - start), s.begin() + pos);

                // 更新start，去找下一个单词
                start = end;
            }
        }
        //删除末尾多余空格
        s.erase(s.begin() + pos, s.end());
        return s;
    }
};
#endif

#if 1
/**
 * 双端队列(栈)
 * 把每一个单词放到一个word字符串里，然后每个word入栈，再出栈
 */
class Solution
{
public:
    string reverseWords(string s)
    {
        int start = 0, end = s.length() - 1;

        //去掉开头和末尾的空格
        while (start <= end && s[start] == ' ') start++;
        while (end >= start && s[end] == ' ') end--;

        deque<string> q;
        string word;

        while (start <= end)
        {
            if (s[start] != ' ')
            {
                word.push_back(s[start]);
            }
            else if (s[start] == ' ' && !word.empty())
            {
                q.push_front(word);     //将单词push到队列的头部
                word.clear();
            }
            start++;
        }
        q.push_front(word);     //添加最后一个单词

        string res;
        while (!q.empty())
        {
            res += q.front();
            res += ' ';
            q.pop_front();
        }
        //去掉最后多加的空格
        // res.erase(res.end() - 1);            //迭代器it
        // res.erase(res.size() - 1, 1);        //下标pos, n
        res.erase(res.end() - 1, res.end());    //迭代器it.b, it.e

        return res;
    }
};
#endif