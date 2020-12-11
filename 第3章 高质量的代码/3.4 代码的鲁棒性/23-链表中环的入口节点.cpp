/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 23-链表中环的入口节点.cpp
*   Author      : huihui571
*   Created date: 2020-12-08
*   Description : 如果一个链表中包含环，如何找出环的入口节点？
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

class Solution {
public:
    /**
     * ①先判断链表是否有环，快慢指针法
     */
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    /**
     * ②还是快慢指针法，找到链表环的入口
     * 从头结点出发一个指针，从相遇节点也出发一个指针，这两个指针每次只走一个步， 那么当这两个指针相遇的时候就是环形入口的节点
     */
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { 
                ListNode* index1 = fast;
                ListNode* index2 = head;
                //从相遇点和起点同时出发，直到第一次相遇
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;      //入口
            }
        }
    }

};