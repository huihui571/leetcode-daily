/*<FH+>***************************************************************
*   Editor      : VSCode
*   File name   : 5713-字符串中不同整数的数目.cpp
*   Author      : huihui571
*   Created date: 2021-03-28
*   Description : 给你一个字符串 word ，该字符串由数字和小写英文字母组成。
* 请你用空格替换每个不是数字的字符。例如，"a123bc34d8ef34" 将会变成 " 123  34 8  34" 。注意，剩下的这些整数间至少要用一个空格隔开："123"、"34"、"8" 和 "34" 。
* 返回对 word 完成替换后形成的 不同 整数的数目。
* 如果两个整数的 不含前导零 的十进制表示不同，则认为这两个整数也不同
*
*<FH->***************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> count;
        //空格替换
        for (auto& ch : word) {
            if (ch - '0' < 0 || ch - '0' > 9) {
                ch = ' ';
            }
        }
        // cout << "word: " << word << endl;
        //去空格
        istringstream is(word);
        string str;
        while (is >> str)
        {
            //去先导0
            while (str.size() > 1 && str[0] == '0')
            {
                str = str.substr(1, str.size() - 1);
            }
            if (str.empty())
                continue;
            count.insert(str);
        }
        return count.size();
    }
};