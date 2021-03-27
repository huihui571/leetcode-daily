/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 67-把字符串转换成整数.cpp
*   Author      : huihui571
*   Created date: 2021-01-18
*   Description : 写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。
*   首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
*   当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；
*   假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
*   该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
*   
*   注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。
*   在任何情况下，若函数不能进行有效的转换时，请返回 0。
*   
*   说明：
*   假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。
*   如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。
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
 * 要主动和面试官交流，询问测试用例形式和范围，考虑非法输入和错误处理等。
 */
class Solution {
public:
    int strToInt(string str) {
        if (str.empty())
            return 0;
        long res = 0;
        int sign = 1;

        int i = 0;
        //跳过空格
        while (str[i] == ' ') i++;  
        //处理正负号
        if (str[i] == '-')
        {
            sign = -1;
        }
        if (str[i] == '-' || str[i] == '+')
        {
            i++;
        }
        //开始转换数字 
        for (; i < str.length(); ++i)
        {
            //处理非法字符
            if (str[i] < '0' || str[i] > '9')
                break;
            res = res * 10 + str[i] - '0';
            //判断范围，注意res是绝对值所以和INT_MAX比，为负数时绝对值可以取到INT_MAX
            if (res >= INT32_MAX && sign == 1)
                return INT32_MAX;
            if (res > INT32_MAX && sign == -1) 
                return INT32_MIN;
        } 
        
        return sign * res;
    }
};