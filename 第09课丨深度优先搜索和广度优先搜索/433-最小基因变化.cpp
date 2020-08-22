/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 433-最小基因变化.cpp
*   Author      : huihui571
*   Created date: 2020-07-30
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
#include <algorithm>

using namespace std;

/**
 * 状态的变化可以看成一个无向无权图，start和end两点间最短路径，使用广度优先遍历求解
 */
#if 1
class Solution
{
public:
    int minMutation(string start, string end, vector<string>& bank)
    {
        int step = 0;
        queue<string> Q;
        unordered_map<string, int> visited;

        Q.push(start);
        visited[start] = 1;
        while (!Q.empty())
        {
            int Q_size = Q.size();
            for (int i = 0; i < Q_size; ++i)
            {
                string cur = Q.front();                         //出队
                Q.pop();
                
                if (cur == end)                                 //访问
                    return step;

                for (string next : get_neighbor(cur, bank))     //邻接节点入队
                {
                    if (!visited[next])
                    {
                        Q.push(next);
                        visited[next] = 1;
                    }
                }            
            }
            step++;         //step记录的实际是遍历过的层数
        }

        return -1;  //没找到，返回-1
    }

    //获取下一个合法的邻接节点，即变异结果。时间复杂度O(length*4)
    vector<string> get_neighbor(string cur, vector<string>& bank)
    {
        vector<char> char_set = {'A', 'C', 'G', 'T'};
        vector<string> neighbors;

        string orign = cur;
        //选一个位置进行变异
        for (int j = 0; j < cur.length(); ++j)    
        {
            //选择用4种碱基中哪个替代
            for (int k = 0; k < char_set.size(); ++k)  
            {
                //选一个和原来不一样的碱基替换
                if (cur[j] == char_set[k])    
                    continue;
                //变异
                cur[j] = char_set[k];  
                //检测变异是否合法，即在bank中
                if (find(bank.begin(), bank.end(), cur) == bank.end())
                    continue;
                //添加进结果
                neighbors.push_back(cur);  
            }
            //复原，因为一次只能变一个位置 
            cur = orign;    
        }

        return neighbors;
    }

    //获取下一个合法的邻接节点，即变异结果。时间复杂度O(length*num_bank)
    vector<string> get_neighbor_2(string cur, vector<string>& bank)
    {
        vector<string> neighbors;
        //返回bank中与cur只差一个字符的string
        for (int i = 0; i < bank.size(); ++i)
        {
            int cnt = 0;
            //统计差异字符数
            for (int j = 0; j < cur.size(); ++j)
            {
                if (bank[i][j] != cur[j])
                    cnt++;
            }
            if (cnt == 1)
                neighbors.push_back(bank[i]);
        }

        return neighbors;
    }
};
#endif
#if 0
class Solution
{
public:
    int minMutation(string start, string end, vector<string>& bank)
    {
        int res = 0;
        queue<string> q;
        unordered_map<string, int> visited;

        vector<char> char_set = {'A', 'C', 'G', 'T'};

        q.push(start);
        visited[start] = 1;
        while (!q.empty())
        {
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i)
            {
                string cur = q.front();         //出队
                q.pop();
                
                /***变异过程，即生成下一个邻接节点过程(有点复杂)，**/
                string orign = cur;
                for (int j = 0; j < cur.length(); ++j)    //选一个位置进行变异
                {
                    for (int k = 0; k < char_set.size(); ++k)   //选择用4种碱基中哪个替代
                    {
                        //选一个和原来不一样的碱基替换
                        if (cur[j] == char_set[k])    
                            continue;
                        //变异
                        cur[j] = char_set[k];  
                        //检测变异是否合法，即在bank中且之前没访问过             
                        if (find(bank.begin(), bank.end(), cur) == bank.end() || visited[cur])    
                            continue;
                        if (cur == end)
                            return res + 1;
                        q.push(cur);      //变异有效，添加进队列
                        visited[cur] = 1;   //置访问标记
                    }
                    cur = orign;    //复原，因为一次只能变一个位置
                }
            }
            res++;      //res记录的实际是遍历过的层数
        }

        return -1;  //没找到，返回-1
    }
};
#endif