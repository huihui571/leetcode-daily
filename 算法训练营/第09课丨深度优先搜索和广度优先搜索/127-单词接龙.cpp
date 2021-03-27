/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 127-单词接龙.cpp
*   Author      : huihui571
*   Created date: 2020-07-31
*   Description : 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。
*   转换需遵循如下规则：每次转换只能改变一个字母。转换过程中的中间单词必须是字典中的单词。
*   说明:
*   如果不存在这样的转换序列，返回 0。
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
 * 每一次变换后的单词看成图的一个节点，整个变换的过程构成一个无向无权图
 * 所以题目转化为求起点和终点之间的最短路径，使用BFS求解
 * 此题中每一个顶点的邻接节点是与它只差一个字母(且在字典中)的单词，我们要自己实现next_neighbor()方法来获取
 */
#if 0
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        int step = 1;
        queue<string> q;
        unordered_map<string, bool> visited;

        //添加到hash_set中，可以实现O(1)的查找
        unordered_set<string> hash_set(wordList.begin(), wordList.end());

        q.push(beginWord);
        visited[beginWord] = true;

        while (!q.empty())
        {
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i)
            {
                string cur = q.front();                         //出队
                q.pop();

                if (cur == endWord)                             //操作
                    return step;

                for (string next : next_neighbor(cur, hash_set))//邻接节点入队
                {
                    if (!visited[next])
                    {
                        q.push(next);
                        visited[next] = true;
                        hash_set.erase(next);   //走过的节点从hash_set里删除，可以减少下一次的搜索时间
                    }
                }
            }
            step++;
        }

        return 0;
    }

    //返回邻居节点的列表
    vector<string> next_neighbor(string curWord, unordered_set<string>& wordList)
    {
        vector<string> neighbors;

        string orign = curWord;
        //选一个位置改变
        for (int i = 0; i < curWord.size(); ++i)
        {
            //从26个字母中选一个替换
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (curWord[i] == c)
                    continue;
                curWord[i] = c;
                if (wordList.find(curWord) == wordList.end())
                    continue;
                neighbors.push_back(curWord);
            }
            curWord = orign;
        }
        return neighbors;
    }
};
#endif

#if 0
/**
 * 写在一起不封装成函数，比上面要快一点
 * 
 */
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        int step = 1;
        queue<string> q;
        unordered_map<string, bool> visited;

        //添加到hash_set中，可以实现O(1)的查找
        unordered_set<string> hash_set(wordList.begin(), wordList.end());

        q.push(beginWord);
        visited[beginWord] = true;

        while (!q.empty())
        {
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i)
            {
                string curWord = q.front();                         //出队
                q.pop();

                if (curWord == endWord)                             //操作
                    return step;

                string orign = curWord;
                //选一个位置改变
                for (int i = 0; i < curWord.size(); ++i)
                {
                    //从26个字母中选一个替换
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        if (curWord[i] == c)
                            continue;
                        curWord[i] = c;
                        /*visited[curWord]放前面复杂度会大大上升，两个都是hash，但是操作规模不一样
                        hash_set大小是bank的大小，而visited如果放前面就是所有可能生成的组合，会造成
                        visited表变得特别大，因为[]操作是存在则返回不存在则插入*/
                        if (hash_set.find(curWord) == hash_set.end() || visited[curWord]) 
                            continue;
                        q.push(curWord);
                        visited[curWord] = true;

                        /*java内置哈希表的典型设计是：
                        键值可以是任何 可哈希化的 类型。并且属于可哈希类型的值将具有 哈希码。此哈希码将用于映射函数以获取存储区索引。
                        每个桶包含一个 数组，用于在初始时将所有值存储在同一个桶中。
                        如果在同一个桶中有太多的值，这些值将被保留在一个 高度平衡的二叉树搜索树中。
                        插入和搜索的平均时间复杂度仍为 O(1)。最坏情况下插入和搜索的时间复杂度是 O(logN)，使用高度平衡的 BST。这是在插入和搜索之间的一种权衡。*/
                        //hash_set.erase(curWord); //加上这一句会有几十毫秒的提速
                    }
                    curWord = orign;
                }
            }
            step++;
        }

        return 0;
    }
};
#endif


/**
 * 双向bfs
 */
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        int step = 1;
        queue<string> begin_Q;
        queue<string> end_Q;
        unordered_map<string, bool> begin_visited;
        unordered_map<string, bool> end_visited;

        //添加到hash_set中，可以实现O(1)的查找
        unordered_set<string> hash_set(wordList.begin(), wordList.end());

        //endWord不在词汇表中的情况
        if (hash_set.find(endWord) == hash_set.end())
            return 0;

        begin_Q.push(beginWord);
        begin_visited[beginWord] = true;
        end_Q.push(endWord);
        end_visited[endWord] = true;

        while (!begin_Q.empty() && !end_Q.empty())
        {
            //选择较短的那个队列遍历
            if (begin_Q.size() > end_Q.size())
            {
                queue<string> tmp = begin_Q;
                begin_Q = end_Q;
                end_Q = tmp;
                unordered_map<string, bool> t = begin_visited;
                begin_visited = end_visited;
                end_visited = t;
            }

            int q_size = begin_Q.size();
            for (int i = 0; i < q_size; ++i)
            {
                string curWord = begin_Q.front();
                begin_Q.pop();

                cout << curWord << endl;
                if (end_visited[curWord])
                    return step;

                string orign = curWord;
                for (int j = 0; j < curWord.length(); ++j)
                {
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        if (curWord[j] == c)
                            continue;
                        curWord[j] = c;
                        if (hash_set.find(curWord) == hash_set.end() || begin_visited[curWord])
                            continue;
                        begin_Q.push(curWord);
                        begin_visited[curWord] = true;
                    }
                    curWord = orign;
                }
            }
            step++;
        }

        return 0;
    }
};