/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 771-宝石与石头.cpp
*   Author      : huihui571
*   Created date: 2020-11-18
*   Description : 给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。 S 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。
J 中的字母不重复，J 和 S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。
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
 * 1. 暴力循环O(mn) 空间O(1)
 * 2. 哈希set O(n) 空间O(n)
 */
class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        int count = 0;
        unordered_set<char> set(J.begin(), J.end());

        for (char s : S)
        {
            if (set.count(s))
                count++;
        }

        return count;
    }
};