/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 24-反转链表.cpp
*   Author      : huihui571
*   Created date: 2020-12-08
*   Description : 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
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
 * 反转箭头法
 * pre, cur, next三元组
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;

        while (cur) {
            ListNode* next = cur->next; //暂存next节点指针
            cur->next = pre;            //反转箭头

            pre = cur;                  //向前一步  
            cur = next;
        }

        return pre;
    }
};