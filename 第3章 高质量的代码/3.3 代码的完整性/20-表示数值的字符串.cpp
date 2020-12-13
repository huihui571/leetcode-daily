/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 20-表示数值的字符串.cpp
*   Author      : huihui571
*   Created date: 2020-12-07
*   Description : 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
*   例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，
*   但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

#if 1
/**
 * 模板匹配法
 * 假设字符串为A.BeC或A.BEC，也就是整数部分为A，小数部分为B，指数部分为C，按顺序扫描判断是否包含这三部分。
 */
class Solution {
private:
    int index = 0;      //全局索引

    /**扫描是否包含无符号数**/
    bool scanUnsignedInteger(string str) {
        int start = index;
        while (str[index] >= '0' && str[index] <= '9') {
            index++;
        }
        return index > start;
    }

    /**扫描是否包含有符号数**/
    bool scanInteger(string str) {
        if (str[index] == '+' || str[index] == '-') {
            index++;
        }
        return scanUnsignedInteger(str);
    }

public:
    bool isNumber(string s) {
        if (s.empty())
            return false;

        s = s + '|';    //添加一个结束标记，否则每次scan都需要判断下标是否大于length

        while (s[index] == ' ') index++;    //跳过开始的空格

        bool numeric = scanInteger(s);      //是否包含整数部分
        if (s[index] == '.') {
            index++;                    //跳过小数点
            numeric = scanUnsignedInteger(s) || numeric;    //小数点两边有一边有数字就行，所以用||
        }
        if (s[index] == 'e' || s[index] == 'E') {
            index++;
            numeric = numeric && scanInteger(s);            //e的两边都要有数字
        }

        while (s[index] == ' ') index++;    //跳过尾部的空格

        return numeric && s[index] == '|';
    }
};
#endif

#if 0
/**
 * 确定有限状态自动机
 * 用“当前处理到字符串的哪个部分”当作状态的表述
 */
class Solution {
private:
    /**定义状态**/
    enum State {
        STATE_INITIAL,              //初始的空格
        STATE_INT_SIGN,             //符号位
        STATE_INTEGER,              //整数部分
        STATE_POINT,                //小数点
        STATE_POINT_WITHOUT_INT,    //左边无整数的小数点
        STATE_FRACTION,             //小数部分
        STATE_EXP,                  //字符e
        STATE_EXP_SIGN,             //指数部分的符号位
        STATE_EXP_NUMBER,           //指数部分的整数部分
        STATE_END,                  //末尾的空格
    };

    /**字符类型**/
    enum CharType {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_SPACE,
        CHAR_ILLEGAL,
    };

    /**将char转行为对应的字符类型**/
    CharType toCharType(char ch) {
        if (ch >= '0' && ch <= '9') {
            return CHAR_NUMBER;
        }
        else if (ch == 'e' || ch == 'E') {
            return CHAR_EXP;
        }
        else if (ch == '.') {
            return CHAR_POINT;
        }
        else if (ch == '+' || ch == '-') {
            return CHAR_SIGN;
        }
        else if (ch == ' ') {
            return CHAR_SPACE;
        }
        else {
            return CHAR_ILLEGAL;
        }
    }

public:
    bool isNumber(string s) {
        /**建立哈希映射，以表驱动的方式进行状态转移**/
        unordered_map<State, unordered_map<CharType, State>> transfer {
            {
                STATE_INITIAL, {                    //在初始状态下
                    {CHAR_SPACE, STATE_INITIAL},            //如果遇到空格，还是转移到初始状态
                    {CHAR_NUMBER, STATE_INTEGER},           //如果遇到数字，转移到整数状态
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT},  //如果遇到小数点，转移到前面无数字的小数点状态
                    {CHAR_SIGN, STATE_INT_SIGN},            //如果遇到符号，转移到整数部分的符号状态
            }
            }, {
                STATE_INT_SIGN, {                   //在整数符号状态下
                    {CHAR_NUMBER, STATE_INTEGER},           //遇到数字，转移到整数状态
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT},  //遇到小数点，转移到前面无数字的小数点状态
                }
            }, {
                STATE_INTEGER, {                    //在整数状态下
                    {CHAR_NUMBER, STATE_INTEGER},           //遇到数字，还是转移到整数状态
                    {CHAR_EXP, STATE_EXP},                  //遇到e，转移到指数状态
                    {CHAR_POINT, STATE_POINT},              //遇到小数点，转移到小数点状态
                    {CHAR_SPACE, STATE_END},                //遇到空格，转移到结束空格状态
                }
            }, {
                STATE_POINT, {                      //在小数点状态下
                    {CHAR_NUMBER, STATE_FRACTION},          //遇到数字，转移到小数状态
                    {CHAR_EXP, STATE_EXP},                  //遇到e，转移到指数状态
                    {CHAR_SPACE, STATE_END},                //遇到空格，转移到结束空格状态
                }
            }, {
                STATE_POINT_WITHOUT_INT, {          //在前面无数字的小数点状态下
                    {CHAR_NUMBER, STATE_FRACTION},          //遇到数字，转移到小数状态
                }
            }, {
                STATE_FRACTION,                     //在小数状态下
                {
                    {CHAR_NUMBER, STATE_FRACTION},          //遇到数字，还是转移到小数状态
                    {CHAR_EXP, STATE_EXP},                  //遇到e，转移到指数状态
                    {CHAR_SPACE, STATE_END},                //遇到空格，转移到结束空格状态
                }
            }, {                                          //在指数状态下
                STATE_EXP,
                {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},        //遇到数字，转移到指数数字状态
                    {CHAR_SIGN, STATE_EXP_SIGN},            //遇到符号，转移到指数符号状态
                }
            }, {                                         //在指数符号状态下
                STATE_EXP_SIGN, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},        //遇到数字，转移到指数数字状态
                }
            }, {
                STATE_EXP_NUMBER, {                 //在指数数字状态下
                    {CHAR_NUMBER, STATE_EXP_NUMBER},        //遇到数字，还是转移到指数数字状态
                    {CHAR_SPACE, STATE_END},                //遇到空格，转移到结束空格状态
                }
            }, {
                STATE_END, {                        //在结束空格状态下
                    {CHAR_SPACE, STATE_END},                //遇到空格，还是转移到结束空格状态
                }
            }
        };

        int len = s.length();
        State st = STATE_INITIAL;

        for (int i = 0; i < len; ++i) {
            CharType typ = toCharType(s[i]);
            if (transfer[st].find(typ) == transfer[st].end()) {
                return false;                   //表中不存在的定义为非法状态
            }
            else {
                st = transfer[st][typ];         //转移状态
            }
        }

        //字符串结尾要么是空格，要么是数字，要么是小数点(前面有数字)
        return st == STATE_END || st == STATE_INTEGER || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st ==
        STATE_POINT;
    }
};
#endif
