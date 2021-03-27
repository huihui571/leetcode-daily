/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 22-链表中倒数第k个节点.cpp
*   Author      : huihui571
*   Created date: 2020-12-08
*   Description : 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
*   例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。
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
 * 双指针法，p1比p2块k步
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head)
            return NULL;
        ListNode* p1 = head;
        for (int i = 0; i < k; ++i)
        {
            if (!p1)
                return NULL;    //如果k小于链表长度
            p1 = p1->next;
        }
        ListNode* p2 = head;
        while (p1) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};