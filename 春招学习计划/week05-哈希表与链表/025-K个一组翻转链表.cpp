/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 025-K个一组翻转链表.cpp 
*   Author      : huihui571
*   Created date: 2021-02-18
*   Description : 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
*   k 是一个正整数，它的值小于或等于链表的长度。
*   如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }
        ListNode* L = new ListNode(-1);
        L->next = head;
        ListNode* p1 = L;
        ListNode* p2 = L;

        while (p2) {
            for (int i = 0; i < k; i++) {
                p2 = p2->next;
                if (p2 == NULL) {
                    return L->next; //不够k个提前结束
                }
            }
            
            ListNode* pStart = p1->next;
            ListNode* pNext = p2->next;     //保存后继

            auto [head, tail] = reverseGroup(pStart, p2);
            p1->next = head;
            tail->next = pNext;

            p1 = pStart;
            p2 = p1;
        }

        return L->next;
    }

    //翻转从head--tail这段子链表，返回翻转后的链表头尾节点
    pair<ListNode*, ListNode*> reverseGroup(ListNode* head, ListNode* tail) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        
        while (pre != tail) {
            ListNode* next = cur->next;
            cur->next = pre;

            pre = cur;
            cur = next;
        }

        return {tail, head};
    }

 };
