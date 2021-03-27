/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 25-合并两个排序的链表.cpp
*   Author      : huihui571
*   Created date: 2020-12-10
*   Description : 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
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

#if 1
/**
 * 遍历，每次选择小的那一个加入结果链表。注意开头判空，以及剩余链表的处理。
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {return l2;}
        if (!l2) {return l1;}
        ListNode* L = new ListNode(-1);
        ListNode* p = L;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
            
        }

        p->next = l1 ? l1 : l2;

        return L->next;
    }
};
#endif

#if 0
/*
*递归法
*/
class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == NULL) return l2;  //终止条件
        if (l2 == NULL) return l1;
        //小的那一个指向其余节点的合并结果
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
     
    }    
};
#endif