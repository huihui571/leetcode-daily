/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 433-最小基因变化.cpp
*   Author      : huihui571
*   Created date: 2020-10-25
*   Description : 一条基因序列由一个带有8个字符的字符串表示，其中每个字符都属于 "A", "C", "G", "T"中的任意一个。
假设我们要调查一个基因序列的变化。一次基因变化意味着这个基因序列中的一个字符发生了变化。
例如，基因序列由"AACCGGTT" 变化至 "AACCGGTA" 即发生了一次基因变化。
与此同时，每一次基因变化的结果，都需要是一个合法的基因串，即该结果属于一个基因库。
现在给定3个参数 — start, end, bank，分别代表起始基因序列，目标基因序列及基因库，请找出能够使起始基因序列变化为目标基因序列所需的最少变化次数。如果无法实现目标变化，请返回 -1。
注意:
起始基因序列默认是合法的，但是它并不一定会出现在基因库中。
所有的目标基因序列必须是合法的。
假定起始基因序列与目标基因序列是不一样的。
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
    int minMutation(string start, string end, vector<string>& bank)
    {
        int step = 0;   //这里求步数，所以初始化为0
        queue<string> begin_Q, end_Q;
        unordered_set<string> begin_visited, end_visited;
        const string ACGT = "ACGT";

        //建立字典
        unordered_set<string> dict(bank.begin(), bank.end());

        if (dict.find(end) == dict.end())
            return -1;

        begin_Q.push(start);
        begin_visited.insert(start);
        end_Q.push(end);
        end_visited.insert(end);

        while (!begin_Q.empty() && !end_Q.empty())
        {
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
                string cur = begin_Q.front();
                begin_Q.pop();

                if (end_visited.find(cur) != end_visited.end())
                    return step;

                string ori = cur;
                for (int j = 0; j < cur.length(); ++j)
                {
                    for (char c : ACGT)
                    {
                        if (cur[j] == c)
                            continue;
                        cur[j] = c;
                        if (dict.find(cur) == dict.end() || begin_visited.find(cur) != begin_visited.end())
                            continue;
                        begin_Q.push(cur);
                        begin_visited.insert(cur);
                    }
                    cur = ori;
                }
            }
            step++;
        }

        return -1;  
    }
};
