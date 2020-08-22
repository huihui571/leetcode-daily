/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 021-合并两个有序链表.cpp
*   Author      : huihui571
*   Created date: 2020-07-15
*   Description : 
*
*<FH->***************************************************************/
#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

#if 0
/*
*遍历l1和l2，每次从二者中选择较小的一个加入L中
*/
class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if (l2 == NULL) return l1;
        if (l1 == NULL) return l2;
        ListNode* L = new ListNode(-1);     //结果链表，带头结点
        ListNode* p = L;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        //L1 L2至多剩下一个
        p->next = (l1 == NULL)? l2: l1;

        return L->next;
   
    }
};
#endif

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