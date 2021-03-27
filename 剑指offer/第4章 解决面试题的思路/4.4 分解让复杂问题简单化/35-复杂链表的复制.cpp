/*<FH+>***************************************************************
*   Editor      : Clion
*   File name   : 35-复杂链表的复制.cpp
*   Author      : huihui571
*   Created date: 2020-12-15
*   Description : 请实现 copyRandomList 函数，复制一个复杂链表。
*   在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
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

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

#if 0
/**
 * 哈希表法
 * 先沿着next指针复制，然后再为每个节点设置random指针。
 * 为避免遍历链表，实现O(1)的查找random指针，用哈希表来保存原节点和复制节点的映射，N'->N->S->S'。
 * note:这个也不能一遍过，小错误还是太多！
 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hash_map;
        Node* p1 = head;
        Node* L = new Node(-1);
        Node* p2 = L;
        while (p1) {
            Node* tmp = new Node(p1->val);
            hash_map[p1] = tmp;      //原节点为key，复制节点为value
            p2->next = tmp;

            p1 = p1->next;
            p2 = p2->next;
        }
        p1 = head;
        p2 = L->next;
        while (p1) {
            p2->random = hash_map[p1->random];      //(N->S)->S'
            p1 = p1->next;
            p2 = p2->next;
        }

        return L->next;
    }
};
#endif

#if 1
/**
 * 考虑在原链表上操作，以利用原链表的random指针。
 * 在每一个节点N后面复制一个N‘，这样N'的random节点可以通过N->random->next来找到，最后再拆分这个链表，得到复制的结果。
 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        Node* p1 = head;
        //复制节点 NOTE:不能在这里设置random，因为后面的节点还没有复制。
        while (p1) {
            Node* tmp = new Node(p1->val);
            tmp->next = p1->next;
            p1->next = tmp;
            p1 = p1->next->next;
        }
        //设置各复制节点的random指针
        p1 = head;
        while (p1) {
            if (p1->random)         //NOTE:解引用一个指针之前要考虑它是否非空
                p1->next->random = p1->random->next;        //关键操作！
            p1 = p1->next->next;
        }
        //拆分链表
        p1 = head;
        Node* p2 = head->next;
        Node* head2 = head->next;
        while (p2->next) {
            p1->next = p1->next->next;
            p2->next = p2->next->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = NULL;      //尾节点单独处理

        return head2;
    }
};
#endif

