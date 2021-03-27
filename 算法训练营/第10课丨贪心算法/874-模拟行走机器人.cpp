/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 874-模拟行走机器人.cpp
*   Author      : huihui571
*   Created date: 2020-09-13
*   Description : 机器人在一个无限大小的网格上行走，从点 (0, 0) 处开始出发，面向北方。该机器人可以接收以下三种类型的命令：
    -2：向左转 90 度
    -1：向右转 90 度
    1 <= x <= 9：向前移动 x 个单位长度
在网格上有一些格子被视为障碍物。
第 i 个障碍物位于网格点  (obstacles[i][0], obstacles[i][1])
机器人无法走到障碍物上，它将会停留在障碍物的前一个网格方块上，但仍然可以继续该路线的其余部分。
返回从原点到机器人所有经过的路径点（坐标为整数）的最大欧式距离的平方。
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
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        int res = 0;
        int x = 0;
        int y = 0;
        //北东南西,顺时针来。这样左转只需要索引+3，右转索引+1
        int dir_x[4] = {0, 1, 0, -1};   
        int dir_y[4] = {1, 0, -1, 0};
        int di = 0;     //方向的索引
        
        //障碍物
        set<pair<int, int>> obs_set;
        for(auto ob : obstacles)
        {
            obs_set.insert(make_pair(ob[0], ob[1]));
        }

        for (auto cmd : commands)
        {
            if (cmd == -2)
                di = (di + 3) % 4;  //这里的转向是相对于当前状态的
            if (cmd == -1)
                di = (di + 1) % 4;
            else
            {
                //每一步都判断障碍
                for (int k = 0; k < cmd; ++k)
                {
                    int nx = x + dir_x[di];
                    int ny = y + dir_y[di];
                    if (obs_set.find(make_pair(nx, ny)) == obs_set.end()) //没有碰到障碍才继续走
                    {
                        x = nx;
                        y = ny;
                        res = max(res, x*x + y*y);
                    }
                    else
                    {
                        break;  //跳出当前指令
                    }
                }
            }
        }

        return res;
    }
};