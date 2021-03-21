/*<FH+>************************************************************************
*   Editor      : Clion
*   File name   : 147-对链表进行插入排序.cpp
*   Author      : huihui571
*   Created date: 2021-03-12
*   Description : 对链表进行插入排序。
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
 * 插入排序。
 * 定义的指针有点多，别乱，在纸上画出来先模拟清楚流程。
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* L = new ListNode(-1);
        L->next = head;
        ListNode* pre = head;

        while (pre->next) {
            ListNode* cur = pre->next;
            //pre是排好序的尾巴，如果cur大于它的话，那cur不用插入了，跳过
            if (cur->val < pre->val) {
                pre->next = cur->next;      //摘下cur
                //找插入位置
                ListNode* p = L;
                while (cur->val > p->next->val) {
                    p = p->next;
                }
                //插在p后面
                cur->next = p->next;
                p->next = cur;
            }
            else {
                pre = cur;
            }
        }

        return L->next;
    }
};

