/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 64-求1+2+…+n.cpp
*   Author      : huihui571
*   Created date: 2021-01-06
*   Description : 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
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
 * for可以用递归代替，if用&&代替，A&&B当A为0时B就不会执行(短路)
 */
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};