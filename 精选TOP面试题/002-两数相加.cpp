/*<FH+>***************************************************************
*   Editor      : VSCode
*   File name   : 002-两数相加.cpp
*   Author      : huihui571
*   Created date: 2021-01-22
*   Description : 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
* 请你将两个数相加，并以相同形式返回一个表示和的链表。你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * 链表基本操做，注意两个链表不一定一样长。当一个结束后，在另一个上面继续遍历，加进位。
 * 思考：如果给的链表不是逆序而是正序呢？
 * 那就要先反转链表，或者用递归达到从后往前访问。
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool flag = false;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* res = new ListNode(-1);
        ListNode* p3 = res;

        while (p1 && p2) {
            int sum = flag ? p1->val + p2->val + 1 : p1->val + p2->val;
            if (sum > 9) {
                flag = true;
                sum = sum % 10;
            }
            else {
                flag = false;
            }
            p3->next = new ListNode(sum);

            p1 = p1->next;
            p2 = p2->next;
            p3 = p3->next;
        }

        ListNode* p4 = p1 ? p1 : p2;
        while (p4) {
            int sum = flag ? p4->val + 1 : p4->val;
            if (sum > 9) {
                flag = true;
                sum = sum % 10;
            }
            else {
                flag = false;
            }
            p3->next = new ListNode(sum);

            p4 = p4->next;
            p3 = p3->next;
        } 
        
        if (flag) {
            p3->next = new ListNode(1);
        }
        
        return res->next;
    }
};