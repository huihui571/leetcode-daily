/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 818-赛车.cpp
*   Author      : huihui571
*   Created date: 2020-11-18
*   Description : 你的赛车起始停留在位置 0，速度为 +1，正行驶在一个无限长的数轴上。（车也可以向负数方向行驶。）
你的车会根据一系列由 A（加速）和 R（倒车）组成的指令进行自动驾驶 。
当车得到指令 "A" 时, 将会做出以下操作： position += speed, speed *= 2。
当车得到指令 "R" 时, 将会做出以下操作：如果当前速度是正数，则将车速调整为 speed = -1 ；否则将车速调整为 speed = 1。  (当前所处位置不变。)
例如，当得到一系列指令 "AAR" 后, 你的车将会走过位置 0->1->3->3，并且速度变化为 1->2->4->-1。
现在给定一个目标位置，请给出能够到达目标位置的最短指令列表的长度
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

class Solution {
public:
    int racecar(int target) {

    }
};