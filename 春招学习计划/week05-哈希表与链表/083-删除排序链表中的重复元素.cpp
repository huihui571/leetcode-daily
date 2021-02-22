/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 083-删除排序链表中的重复元素.cpp 
*   Author      : huihui571
*   Created date: 2021-02-19
*   Description : 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode* cur = head;
        while (cur->next) {
            if (cur->val == cur->next->val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else {
                cur = cur->next;
            }
        }
        return head;
    }
};
