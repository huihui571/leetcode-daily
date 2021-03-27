/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 126-单词接龙II.cpp
*   Author      : huihui571
*   Created date: 2020-08-01
*   Description : 给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。
*   转换需遵循如下规则：
*   每次转换只能改变一个字母。
*   转换后得到的单词必须是字典中的单词。
*   说明:
*   如果不存在这样的转换序列，返回一个空列表。
*   所有单词具有相同的长度。
*   所有单词只由小写字母组成。
*   字典中不存在重复的单词。
*   你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * 依然使用bfs框架，队列中保存的不是同一层次的节点，而是从起点到同一层次节点的路径。
 */
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        vector<vector<string>> res;
        queue<vector<string>> path_queue;    //路径的队列
   
        //记录这一个层级被访问过的节点
        unordered_set<string> visited;

        //添加到hash_set中，可以实现O(1)的查找
        unordered_set<string> dict(wordList.begin(), wordList.end());
        //endWord不在词汇表中的情况
        if (dict.find(endWord) == dict.end())
            return res;
        
        path_queue.push({beginWord});
        int level = 1;
        int minlevel = INT_MAX;

        while (!path_queue.empty())
        {
            int q_size = path_queue.size();
            for (int i = 0; i < q_size; ++i)
            {
                vector<string> path = path_queue.front();           //队首出队
                path_queue.pop();

                //排除不是最短的路径
                if (path.size() > minlevel)
                    break;

                string curWord = path.back();  //路径中最后一个单词

                cout << curWord << endl;
                if (curWord == endWord)     //找到终点
                {
                    minlevel = level;   //记录下最短的层数
                    res.push_back(path);
                }

                string origin = curWord;
                for (int i = 0; i < curWord.length(); ++i)
                {
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        if (curWord[i] == c)
                            continue;
                        curWord[i] = c;
                        if (dict.find(curWord) == dict.end() || visited.find(curWord) != visited.end())
                            continue;
                        //path是上一个level生成的路径，这一个level每一次变异都会生成一条新路径，所以要拷贝
                        vector<string> newpath = path;
                        newpath.push_back(curWord);     //生成一条新路径
                        visited.insert(curWord);    //置访问标记
                        path_queue.push(newpath);   //将生成的新路径入队列
                    }
                    curWord = origin;
                } 
            }
            level++;
        }

        return res;
    }
};