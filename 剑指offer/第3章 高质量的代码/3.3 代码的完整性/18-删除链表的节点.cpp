/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 18-删除链表的节点.cpp
*   Author      : huihui571
*   Created date: 2020-12-06
*   Description : 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
*   返回删除后的链表的头节点。
*   注意：此题对比原题有改动
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


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 题目改的没有一点意思了，还是看原题去吧
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* L = new ListNode(-1);
        L->next = head;
        ListNode* pre = L;
        ListNode* cur = head;

        while (cur) {
            if (cur->val == val) {
//                ListNode* tmp = cur;
                pre->next = cur->next;
//                delete tmp;           //题目不要求删除
            }
            pre = pre->next;
            cur = cur->next;
        }

        return L->next;
    }
};
