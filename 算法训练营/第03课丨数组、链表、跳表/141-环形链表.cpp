/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 141-环形链表.cpp
*   Author      : huihui571
*   Created date: 2020-07-05
*   Description : 给定一个链表，判断链表中是否有环。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
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
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 快慢指针法，时间复杂度O(n)，空间复杂度O(1)
 * 基本操作，重点掌握
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode* fast = head;
        ListNode* low = head;

        while (fast != NULL && fast->next != NULL)  //易错。fast作为工作指针肯定要判空，在此基础上再判断fast->next(因为下面有对fast->next的引用)，缺一不可。
        {
            low = low->next;
            fast = fast->next->next;
            if (low == fast)
            {
                return true;
            }
        }
        return false;
    }
        
};

#if 0
/**
 * hash_map法，时间复杂度O(n)，空间复杂度O(n)
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_map<ListNode *, int> visited;
        ListNode* p = head;
        while (p)
        {
            visited[p]++;
            if (visited[p] > 1)
            {
                return true;
            }
            p = p->next;
        }

        return false;
    }
        
};
#endif

