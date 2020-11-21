/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 127-单词接龙.cpp
*   Author      : huihui571
*   Created date: 2020-10-25
*   Description : 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
    每次转换只能改变一个字母。
    转换过程中的中间单词必须是字典中的单词。
说明:
    如果不存在这样的转换序列，返回 0。
    所有单词具有相同的长度。
    所有单词只由小写字母组成。
    字典中不存在重复的单词。
    你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
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
 * 双向BFS
 */
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        int step = 1;   //转换序列的长度，初始为1
        queue<string> begin_Q, end_Q;
        unordered_set<string> begin_visited, end_visited;

        //字典添加到hash_set中，可实现O(1)的查找
        unordered_set<string> dict(wordList.begin(), wordList.end());

        //endword 不在字典中的情况
        if (dict.find(endWord) == dict.end())
            return 0;

        begin_Q.push(beginWord);
        begin_visited.insert(beginWord);
        end_Q.push(endWord);
        end_visited.insert(endWord);

        while (!begin_Q.empty() && !end_Q.empty())
        {
            //选择较短的那个队列遍历
            if (end_Q.size() < begin_Q.size())
            {
                queue<string> tmp_Q = begin_Q;
                unordered_set<string> tmp_v = begin_visited;
                begin_Q = end_Q;
                begin_visited = end_visited;
                end_Q = tmp_Q;
                end_visited = tmp_v;
            }

            int q_size = begin_Q.size();
            for (int i = 0; i < q_size; ++i)
            {
                string curWord = begin_Q.front();       //队首依次出队
                begin_Q.pop();

                //两边相遇，返回结果
                if (end_visited.find(curWord) != end_visited.end())
                    return step;

                //开始变异
                string orign = curWord;
                //选一个位置
                for (int j = 0; j < curWord.length(); ++j)
                {
                    //选一个字母
                    for (char c = 'a'; c <= 'z'; c++)
                    {   
                        //跳过自己
                        if (curWord[j] == c)
                            continue;   
                        curWord[j] = c;  
                        //字典里没有，或者之前已经访问过
                        if (dict.find(curWord) == dict.end() || begin_visited.find(curWord) != begin_visited.end())
                            continue;
                        cout << "hhhhhhh" << endl;
                        begin_Q.push(curWord);          //邻接节点入队
                        begin_visited.insert(curWord);  //置访问标记
                    }
                    curWord = orign;    //一次只能改变一个位置，所以这里要还原
                }
            }
            step++;     //每访问一层加1
        }

        return 0;   //不能相遇，就是没有找到结果，返回0
    }
};