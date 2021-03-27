/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 206-反转链表.cpp
*   Author      : huihui571
*   Created date: 2020-07-06
*   Description : 反转一个单链表。
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * pre,cur,next三元组，反转箭头。
 * 基本操作，熟练掌握。
 */
class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre = NULL;   //pre最开始指向的是最终的尾节点后面，为NULL
        ListNode* cur = head;

        while (cur != NULL)
        {
            ListNode* next = cur->next;     //暂存后继
            cur->next = pre;                //反转箭头
            pre = cur;
            cur = next;                     //后移指针   
        }
        return pre;
    }
};