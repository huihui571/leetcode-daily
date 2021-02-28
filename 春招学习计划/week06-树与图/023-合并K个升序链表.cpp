/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 023-合并K个升序链表.cpp 
*   Author      : huihui571
*   Created date: 2021-02-24
*   Description : 给你一个链表数组，每个链表都已经按升序排列。
*   请你将所有链表合并到一个升序链表中，返回合并后的链表。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * 关键是每次怎么从K个链表的head中选一个最小的
 * 可以遍历，时间复杂度O(k)
 * 用优先队列/堆，时间复杂度O(logk)
 */
class Solution {
public:
    //cmp是一个可调用对象，这里用重载()的方式即仿函数来实现。另外两种方式是函数指针和lambada表达式
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;

        //建立大小为k的小根堆
        for (auto head : lists) {
            if (head)
                q.push(head);
        }

        ListNode* L = new ListNode(-1);
        ListNode* pre = L;
        while (!q.empty()) {
            ListNode* cur = q.top();
            q.pop();
            pre->next = cur;

            pre = cur;
            if (cur->next)
                q.push(cur->next);
        }

        return L->next;
    }
};

