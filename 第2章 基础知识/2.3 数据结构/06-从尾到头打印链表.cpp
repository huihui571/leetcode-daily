/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 06-从尾到头打印链表.cpp
*   Author      : huihui571
*   Created date: 2020-11-23
*   Description : 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#if 0
/**
 * 用栈实现逆序打印
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        deque<int> st;

        ListNode * p = head;
        while (p) {
            st.push_front(p->val);
            p = p->next;
        }

        while (!st.empty()) {
            res.push_back(st.front());
            st.pop_front();
        }

        return res;
    }
};
#endif

#if 1
/**
 * 用递归来实现倒序访问链表
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;

        reverse_print_recur(head, res);
        return res;
    }

    void reverse_print_recur(ListNode* head, vector<int>& res) {
        if (head == NULL)
            return;

        if (head->next) {
            reverse_print_recur(head->next, res);
        }

        res.push_back(head->val);   //在递归出来的时候访问，就是先递归访问它后面的节点，再访问它自身
    }
};
#endif