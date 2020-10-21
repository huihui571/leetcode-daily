/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 860-柠檬水找零.cpp
*   Author      : huihui571
*   Created date: 2020-09-09
*   Description : 在柠檬水摊上，每一杯柠檬水的售价为 5 美元。
顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
注意，一开始你手头没有任何零钱。
如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
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
 * 模拟过程就行了，贪心只是一种思想，每次先用手里最大面额的去凑。
 */
class Solution
{
public:
    bool lemonadeChange(vector<int>& bills)
    {
        int five = 0;
        int ten = 0;

        for (auto b : bills)
        {
            // switch (b) 
            // {
            //     case 5: five++; break;
            //     case 10: ten++; five--; break;
            //     case 20: if (ten > 0){ten--; five--;}
            //                 else {five -= 3;} break;
            // }
            // if (five < 0)
            //     return false;
            
            if (b == 5)
            {
                five++;  
            }
            else if (b == 10)
            {
                ten++;
                five--;
                if (five < 0)
                    return false;
            }
            else
            {
                if (ten > 0 && five > 0)
                {
                    ten--;
                    five--;
                }
                else if (five > 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
            
        }

        return true;
    }
};