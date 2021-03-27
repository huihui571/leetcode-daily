/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 773-滑动谜题.cpp
*   Author      : huihui571
*   Created date: 2020-10-25
*   Description : 在一个 2 x 3 的板上（board）有 5 块砖瓦，用数字 1~5 来表示, 以及一块空缺用 0 来表示.
一次移动定义为选择 0 与一个相邻的数字（上下左右）进行交换.
最终当板 board 的结果是 [[1,2,3],[4,5,0]] 谜板被解开。
给出一个谜板的初始状态，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。
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

#if 1
/**
 * BFS
 * 把每次的变化看成图的一个节点，那么最少步数问题可以转化为图的最短路径
 * 技巧：把二维数组压缩成一个一维的字符串方便处理，需要将每个元素的邻居(上下左右)做一个映射
 */
class Solution
{
private:
    //在一维字符串中，索引i在二维数组中的的相邻索引为neighbor[i]，不考虑顺序
    vector<vector<int>> neighbor = 
    {
        {1, 3},
        {0, 2, 4},
        {1, 5},
        {0, 4},
        {1, 3, 5},
        {2, 4}
    };
public:
    int slidingPuzzle(vector<vector<int>>& board)
    {
        int step = 0;
        string start = "";
        string end = "123450";
        //将2x3数组转换为字符串
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                start.push_back(board[i][j] + '0');
            }
        }

        //BFS框架开始
        queue<string> Q;
        unordered_set<string> visited;

        Q.push(start);
        visited.insert(start);

        while (!Q.empty())
        {
            int q_size = Q.size();
            for (int i = 0; i < q_size; ++i)
            {
                string cur = Q.front();         //头结点依次出队
                Q.pop();

                if (cur == end)                 
                    return step;

                //找到数字0的位置
                int idx = 0;
                while (cur[idx] != '0') {idx++;}
                //开始移动
                for (int adj : neighbor[idx])
                {
                    string new_board = cur;     //这里是每次都new了一个新节点，如果在原来的基础上修改的话，后面要记得改回去
                    swap(new_board, adj, idx);
                    if (visited.find(new_board) == visited.end())   //如果没访问过
                    {
                        Q.push(new_board);                  //邻接点入队
                        visited.insert(new_board);          //置访问标记
                    }
                }
            }
            step++;
        }

        return -1;  //没搜到结果才会执行到这里
    }

    //交换字符串i,j处的字符
    void swap(string& s, int i, int j)
    {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
};
#endif