/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 058-最后一个单词的长度.cpp
*   Author      : huihui571
*   Created date: 2020-11-18
*   Description : 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
如果不存在最后一个单词，请返回 0 。
说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。
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

#if 1
/**
 * 两个指针end和start，end先从后往前移，找到第一个不是空格的字符位置。
 * 然后从该位置接着移动start，直到遇到空格。
 * 注意边界
 */
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int end = s.length() - 1;
        while (end >= 0 && s[end] == ' ') {end--;}

        if (end < 0) return 0;

        int start = end;
        while (start >= 0 && s[start] != ' ') {start--;}

        return end - start;
    }
};
#endif

#if 0
/**
 * 有限状态机
 * 从后往前逐个处理，依次定义状态：0-->末尾的空格，1-->最后一个单词，2-->单词前面的空格或者字符串开头
 */
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int len = s.length();
        if (len == 0)
            return 0;
        int state = s[len - 1] == ' ' ? 0 : 1;
        int start = len - 1, end = len - 1;

        while (len)
        {
            if (state == 0 && s[len - 1] != ' ')
            {
                start = len - 1;
                state = 1;
            }
            if (state == 1)
            {
                if (s[len - 1] == ' ')
                {
                    end = len - 1;
                    break;
                }      
                else if (len - 1 == 0 && s[len - 1] != ' ') 
                {
                    end = -1;
                    break;
                }        
                // state = 2;     
            }
            len--;
        }  
        return start - end;
    }
};
#endif