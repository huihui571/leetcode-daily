/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 17-打印从1到最大的n位数.cpp
*   Author      : huihui571
*   Created date: 2020-12-05
*   Description : 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
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

/**
 * 题目中没有限定n的范围，要意识到这是一个大数问题
 * 用字符串来模拟大数，要实现一个加1运算和打印
 */
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
         if (n <= 0)
             return res;

         string number(n, '0');
         while (!increment(number)) {
             res.push_back(strTonum(number));
         }

        return res;
    }

    //为字符串表示的数加1
    bool increment(string& number) {
        bool isOverflow = false;
        int lastBit = 0;          //存储进位
        int len = number.length();

        //从最低位开始处理
        for (int i = len - 1; i >= 0; --i) {
            int sum = number[i] - '0' + lastBit;   //当前位先加上低位的进位
            if (i == len - 1) {         //在最低位上加1
                sum++;
            }
            if (sum > 9) {              //发生进位
                if (i == 0) {
                    isOverflow = true;    //最高位发生进位-->溢出
                }
                else {
                    lastBit = 1;
                    sum -= 10;
                    number[i] = sum + '0';
                }
            }
            else {
                number[i] = sum + '0';
                break;                  //如果当前不用进位，那么后面也不用处理了
            }
        }

        return isOverflow;
    }

    //去掉字符串前面多余的0，然后调用stoi转换
    int strTonum(const string& number) {
        string s;
        int begin = 0;
        while (number[begin] == '0') begin++;   //去除前面的0
        while (begin < number.length()) {
            s += number[begin++];
        }
        return stoi(s);
    }
};
