/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 58-II-左旋转字符串.cpp
*   Author      : huihui571
*   Created date: 2021-01-03
*   Description : 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
*   比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
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

#if 0
/**
 * push_back后再erase，执行时间比较慢，难道是erase比较耗时？
 * Note:任何再vector前部做的操作复杂度都是O(n)的，再前部插入和删除数据非常低效。
 */
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        char tmp;
        for (int i = 0; i < n; ++i) {
            tmp = s[0];
            s.push_back(tmp);
            s.erase(0, 1);
        }
        return s;
    }
};
#endif

#if 1
/**
 * 开一个辅助数组，直接按索引复制元素。
 * Note:[]访问比push_back()要快。是因为下标访问需提前分配好数组所需的空间，而使用push_back和insert会造成不断的重新分配空间。
 * 提升vector性能：
 * - 访问vector速度：下标 > 迭代器 > at();
 * - 填充或拷贝vector：用[]赋值而不是push_back或insert;
 * - 在尾部插入元素时用emplace_back而不是push_back;
 */
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string res(s.length(), 0);
        int idx = 0;
        for (int i = n; i < s.length(); ++i) {
            res[idx++] = s[i];
        }
        for (int i = 0; i < n; ++i) {
            res[idx++] = s[i];
        }
        return res;
    }
};
#endif
