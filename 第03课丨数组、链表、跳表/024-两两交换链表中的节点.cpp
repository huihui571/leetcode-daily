/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 024-两两交换链表中的节点.cpp
*   Author      : huihui571
*   Created date: 2020-07-12
*   Description : 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
*先将第一个节点删除，再插入到第二个节点后面
*注意先搭框架，while写完先写pre工作指针后移，然后再填充具体操作内容。
*/
class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* L = new ListNode(-1);
        L->next = head;

        ListNode* pre = L;
        while (pre->next != NULL)
        {
            if (pre->next->next == NULL)    //奇数个情况
            {
                break;
            }
            //删除节点1
            ListNode* tmp = pre->next;
            pre->next = pre->next->next;
            //插入节点2后面
            tmp->next = pre->next->next;
            pre->next->next = tmp;
            //后移两步
            pre = pre->next->next;
        }

        return L->next;
    }
};