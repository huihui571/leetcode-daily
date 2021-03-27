/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 18-删除链表的节点原题.cpp
*   Author      : huihui571
*   Created date: 2020-12-06
*   Description : 给定单向链表的头指针和一个节点指针，定义一个函数在O(1)时间内删除该节点。
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

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 如果要找node的pre节点来删除，那么肯定要遍历链表，时间复杂度为O(n)
 * 不一定要找到pre节点，我们可以把要next节点的内容复制到当前节点，然后删除next节点。
 * 注意：要删除的节点位于链表尾部的时候，依然要从头开始遍历找pre节点来删除。
 * 时间复杂度：这样前n-1个节点是O(1)，尾节点是O(n)，总体平均是O(1)
 */
ListNode* DeleteNode(ListNode* head, ListNode* node) {
    //检查输入合法性
    if (head == NULL || node == NULL)   
        return NULL;

    ListNode* L = new ListNode(-1);
    L->next = head;

    //node不是尾节点
    if (node->next) {
        node->val = node->next->val;
        //删除tmp
        ListNode* tmp = node->next;
        node->next = node->next->next;
        delete tmp;
    }
    else {
        ListNode* pre = L;
        ListNode* cur = head;
        //找到尾节点
        while (cur->next) {
            pre = pre->next;
            cur = cur->next;
        }
        //删除cur
        pre->next = cur->next;
        delete cur;
    }

    return L->next;
}
