/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 5710-积压订单中的订单总数.cpp
*   Author      : huihui571
*   Created date: 2021-03-21
*   Description :给你一个二维整数数组 orders ，其中每个 orders[i] = [pricei, amounti, orderTypei] 表示有 amounti 笔类型为 orderTypei 、价格为 pricei 的订单。
*   订单类型 orderTypei 可以分为两种：
*       0 表示这是一批采购订单 buy
*       1 表示这是一批销售订单 sell
*   注意，orders[i] 表示一批共计 amounti 笔的独立订单，这些订单的价格和类型相同。对于所有有效的 i ，由 orders[i] 表示的所有订单提交时间均早于 orders[i+1] 表示的所有订单。
*   存在由未执行订单组成的 积压订单 。积压订单最初是空的。提交订单时，会发生以下情况：
*       如果该订单是一笔采购订单 buy ，则可以查看积压订单中价格 最低 的销售订单 sell 。如果该销售订单 sell 的价格 低于或等于 当前采购订单 buy 的价格，则匹配并执行这两笔订单，并将销售订单 sell 从积压订单中删除。否则，采购订单 buy 将会添加到积压订单中。
*       反之亦然，如果该订单是一笔销售订单 sell ，则可以查看积压订单中价格 最高 的采购订单 buy 。如果该采购订单 buy 的价格 高于或等于 当前销售订单 sell 的价格，则匹配并执行这两笔订单，并将采购订单 buy 从积压订单中删除。否则，销售订单 sell 将会添加到积压订单中。
*   输入所有订单后，返回积压订单中的 订单总数 。由于数字可能很大，所以需要返回对 109 + 7 取余的结果。
*
*<FH->***************************************************************/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<PII> A, B;
        int MOD = 1e9 + 7;
        long long ans = 0;
        
        for(auto &i : orders){
            if(i[2] == 0)   //buy
                A.push({i[0], i[1]});
            else            //sell
                B.push({-i[0], i[1]});
            ans += i[1];
            //消除
            while(!A.empty()){
                if(B.empty() || -B.top().first > A.top().first)
                    break;
                PII x = A.top();
                A.pop();
                PII y = B.top();
                B.pop();
                
                int nu = min(x.second, y.second);
                x.second -= nu;
                y.second -= nu;
                ans -= 2 * nu;
                if(x.second)
                    A.push(x);
                else
                    B.push(y);
            }
            // cout << " " << ans << endl;
        }
        return ans % MOD;
    }
};
