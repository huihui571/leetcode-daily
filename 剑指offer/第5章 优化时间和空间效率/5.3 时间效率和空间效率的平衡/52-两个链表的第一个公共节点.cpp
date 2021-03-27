/*<FH+>***************************************************************
*   Editor      : CLion
*   File name   : 52-两个链表的第一个公共节点.cpp
*   Author      : huihui571
*   Created date: 2020-12-31
*   Description : 输入两个链表，找出它们的第一个公共节点。
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
 * 1. 哈希表
 * 2. 两个栈，弹出的时候第一个不同的节点
 * 3. 双指针，短的遍历到末尾后指向另一个的头节点。基于L1+C+L2 = L2+C+L1
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;

        while (p1 != p2) {
            p1 = p1 != NULL ? p1->next : headB;
            p2 = p2 != NULL ? p2->next : headA;
        }

        return p1;
    }
};
