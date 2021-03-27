/*<FH+>***************************************************************
*   Editor      : Sublime Text 3
*   File name   : 146-LRU缓存机制.cpp
*   Author      : huihui571
*   Created date: 2020-11-02
*   Description : 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。
*   它应该支持以下操作： 获取数据 get 和 写入数据 put 。
    获取数据 get(key) - 如果关键字 (key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。
    写入数据 put(key, value) - 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字/值」。
 当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
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

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(NULL), next(NULL) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(NULL), next(NULL) {}
};

class LRUCache{
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;
public:
    LRUCache(int _capacity):capacity(_capacity),size(0) {
        //使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        //开始这两个节点互相连接
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key))
            return -1;

        DLinkedNode* node = cache[key]; //通过哈希表获取key在双向链表中的定位
        moveTohead(node);           //移动至头部
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.count(key))
        {
            DLinkedNode* node = cache[key];
            node->value = value;    //存在则更新value
            moveTohead(node);
        }
        else
        {
            DLinkedNode* node = new DLinkedNode(key, value);//不存在则创建一个新节点
            cache[key] = node;                              //添加索引到哈希表
            addTohead(node);        //添加至头部
            size++;

            if (size > capacity)
            {
                //超出容量，需删除双向链表尾部节点
                DLinkedNode* node = removeTail();
                cache.erase(node->key);         //别忘了删除索引
                //收尾工作
                delete node;
                size--;
            }
        }
    }

    void moveTohead(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void addTohead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        node->prev->next = tail;
        tail->prev = node->prev;

        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */