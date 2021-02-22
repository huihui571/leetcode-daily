/*<FH+>************************************************************************
*   Editor      : Vim
*   File name   : 146-LRU缓存机制.cpp 
*   Author      : huihui571
*   Created date: 2021-02-15
*   Description : 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
*   实现 LRUCache 类：
*       LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
*       int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
*       void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
*   进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？
*
*<FH->************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/**
 * 用一个双向链表存缓存值(key-value)，每次访问过的节点移动到链表头部，这样从链表头到尾最近使用次数依次递减，
 * 当缓存超出容量时，删掉链表尾的节点，它就是最近最少使用的。
 * 用哈希表存key到链表节点的映射，达到O(1)时间内访问。
 */
struct DLinkNode {
    int key, val;
    DLinkNode* pre;
    DLinkNode* next;
    DLinkNode(int _key, int _val) : key(_key), val(_val), pre(NULL), next(NULL) {};
};

class LRUCache {
private:
    unordered_map<int, DLinkNode*> cache;
    DLinkNode* head;
    DLinkNode* tail;
    int capacity;
    int size;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        //初始化哑头尾节点
        this->head = new DLinkNode(0, 0);
        this->tail = new DLinkNode(0, 0);
        this->head->next = this->tail;
        this->tail->pre = this->head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        DLinkNode* node = cache[key];   //找到链表节点
        moveToHead(node);               //访问过的就移到前面
        return node->val;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            DLinkNode* node = cache[key];
            node->val = value;      //更新value
            moveToHead(node);       //移到前面
        }
        else {
            DLinkNode* node = new DLinkNode(key, value);
            addToHead(node);        //新节点加到前面
            cache[key] = node;      //添加索引
            this->size++;

            if (this->size > this->capacity) {  //超出容量则删除尾部
                DLinkNode* tail = removeTail();
                cache.erase(tail->key);         //别忘了删除索引
                this->size--;
                delete tail;
            }
        }
    }

    void addToHead(DLinkNode* node) {
        node->next = this->head->next;
        this->head->next->pre = node;
        this->head->next = node;
        node->pre = this->head;
    }

    void moveToHead(DLinkNode* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        node->next = NULL;
        node->pre = NULL;
        
        addToHead(node);
    }
    
    DLinkNode* removeTail() {
        DLinkNode* node = tail->pre;
        node->pre->next = node->next;
        node->next->pre = node->pre;
        node->next = NULL;
        node->pre = NULL;
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
