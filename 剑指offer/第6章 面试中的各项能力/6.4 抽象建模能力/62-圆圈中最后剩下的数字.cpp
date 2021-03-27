/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 62-圆圈中最后剩下的数字.cpp
*   Author      : huihui571
*   Created date: 2021-01-06
*   Description : 0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。
* 例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

#if 0
/**
 * 约瑟夫环问题
 * 用环形链表模拟圆圈，时间复杂度O(mn)，超时
 */
class Solution {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
    };
public:
    int lastRemaining(int n, int m) {
        if (n < 1 || m < 1)
            return -1;
        //构造链表
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        for (int i = 1; i < n; ++i) {
            p->next = new ListNode(i);
            p = p->next;
        }
        p->next = head;         //成环

        ListNode* pre = p;      //pre指向最后一个元素
        p = head;               //p指向起点
        while (p->next != p) {
            //走m-1步
            for (int i = 0; i < m - 1; ++i) {
                pre = p;
                p = p->next;
            }
            //删除节点
            ListNode* tmp = p;
            pre->next = p->next;
            p = p->next;
            delete tmp;
        }

        return p->val;
    }
};
#endif

#if 1
/**
 * f(i) = (f(i - 1) + M) % i 数学推导暂时没看懂
 */
class Solution {
public:
    int lastRemaining(int n, int m) {
//        return yuesefu(n, m);
        int f = 0;
        for (int i = 2; i <= n; ++i) {
            f = (f + m) % i;
        }
        return f;
    }

    int yuesefu(int n, int m) {
        if (n == 1) {
            return 0;           //返回下标从0开始，只有一个元素就是剩余的元素
        }
        else {
            return (yuesefu(n - 1, m) + m) % n;     //n是总共的个数
        }
    }
};
#endif