/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 025-K个一组翻转链表.cpp
*   Author      : huihui571
*   Created date: 2020-07-12
*   Description : 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
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

#if 0
/**
 * 根据head，tail指针反转子链表。注意反转之后子链表与原链表的拼接以及head,tail顺序。
 */
class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (k == 1) return head;

        ListNode* L = new ListNode(-1);
        L->next = head;
        ListNode* pre = L;

        while (pre->next != NULL)
        {
            //移动tail指针到指定位置
            ListNode* tail = pre;
            for (int i = 0; i < k; ++i)
            {
                tail = tail->next;
                if (tail == NULL)
                {
                    return L->next;
                }
            }

            ListNode* next_tail = tail->next;   //保存当前子链表的后继节点

            //反转子链表
            pair<ListNode*, ListNode*>ret = reverse(head, tail);
            head = ret.first;
            tail = ret.second;

            //将子链表接回原链表
            pre->next = head;
            tail->next = next_tail;

            //移动新的pre，head
            pre = tail;
            head = tail->next;
        }

        return L->next;
    }

    //反转链表的一部分，根据给定的head和tail
    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail)
    {
        ListNode* pre = head;
        ListNode* cur = pre->next;
        pre->next = NULL;

        while (pre != tail)
        {
            ListNode* next = cur->next; //暂存    
            cur->next = pre;            //反转
            pre = cur;                  //后移
            cur = next;
        }
        //返回新的头与尾
        return { tail, head };
    }
};
#endif

#if 1
/**
 * 递归。反转k个节点之后，问题变为k->next起始链表的相同子问题。
 */
class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (head == NULL)
            return head;

        ListNode* p1 = head;    //子链表开始
        ListNode* p2 = head;    //子链表结束

        for (int i = 0; i < k - 1; ++i)
        {
            p2 = p2->next;
            if (p2 == NULL)
                return head;    //剩余部分不足K，什么都不做，返回原链表
        }

        ListNode* p2_next = p2->next;      //反转子链表会造成断链，暂存后继
        ListNode* child_head = reverse_child(p1, p2);
        p1->next = reverseKGroup(p2_next, k);  //已反转部分的尾指针，指向下一个子链表反转之后的头

        return child_head;
    }

    //反转指定子链表head--tail，返回反转后子链表头结点
    ListNode* reverse_child(ListNode* head, ListNode* tail)
    {
        ListNode* pre = NULL;
        ListNode* cur = head;

        while (pre != tail)
        {
            ListNode* next = cur->next; //暂存    
            cur->next = pre;            //反转
            pre = cur;                  //后移
            cur = next;
        }
        //返回新的头指针
        return pre;
    }

};
#endif

int main()
{
    int a1[] = { 1, 2, 3, 4, 5};
    ListNode* l1 = new ListNode(-1);
    ListNode* p1 = l1;
    for (int i = 0; i < 5; ++i) {
        ListNode* ptmp = new ListNode(a1[i]);
        p1->next = ptmp;
        p1 = p1->next;
    }
    Solution solution;

    ListNode* l3 = solution.reverseKGroup(l1->next, 2);
    for (; l3 != NULL; l3 = l3->next) {
        cout << l3->val << endl;
    }
    
}
