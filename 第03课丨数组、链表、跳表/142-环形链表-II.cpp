/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 142-环形链表-II.cpp
*   Author      : huihui571
*   Created date: 2020-07-05
*   Description : 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
说明：不允许修改给定的链表。
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
 * 要返回第一个节点，无法用快慢指针，因为指针不一定相遇在环的什么位置。
 * hash_map法，时间复杂度O(n)，空间复杂度O(n)
 * visited数组存储节点访问次数，大于1说明重复访问
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
