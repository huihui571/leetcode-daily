/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 019-删除链表的倒数第N个节点.cpp 
*   Author      : huihui571
*   Created date: 2021-02-20
*   Description : 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*   进阶：你能尝试使用一趟扫描实现吗？
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

/**
 * 双指针，哑结点
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* L = new ListNode(-1);
        L->next = head;
        ListNode* p1 = L;
        ListNode* p2 = L;

        for (int i = 0; i < n; i++) {
            p1 = p1->next;
        }

        while (p1->next) {
            p1 = p1->next;
            p2 = p2->next;
        }

        ListNode* tmp = p2->next;
        p2->next = p2->next->next;
        delete tmp;

        return L->next;
    }
};

