/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : jz06-从尾到头打印链表.cpp 
*   Author      : huihui571
*   Created date: 2021-02-21
*   Description : 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
* 递归
*/
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        print(head, res);

        return res;
    }

    void print(ListNode* head, vector<int>& res) {
        if (head == NULL)
            return;

        print(head->next, res);
        res.push_back(head->val);
    }
};
