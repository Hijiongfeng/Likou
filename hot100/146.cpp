#include<bits/stdc++.h>

using namespace std;

/*
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；
如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，
则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

*/

/*
LRU 缓存可以通过一个 哈希表和双端链表 实现
哈希表找到链表节点的位置
如果key存在 就移动到链表头部
不存在 增加一个节点，在链表头部

*/


struct DLinkedNode
{
    int key,value;          // 节点里面存储 key；是为了超出容量的时候，找到key ，在哈希表中进行删除
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode():key(0),value(0),prev(nullptr),next(nullptr){}
    DLinkedNode(int _key,int _value) : key(_key),value(_value),prev(nullptr),next(nullptr){}
};


class LRUCache {
private:
    unordered_map<int,DLinkedNode*> cache;
    DLinkedNode* head;                          // 定义一个初始的头结点 和尾节点
    DLinkedNode* tail;
    int size;
    int capacity;
public:
    LRUCache(int capacity) : capacity(capacity),size(0){            // 初始化 首尾 节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!cache.count(key)){              // 不存在key 返回 -1；
            return -1;
        }
        DLinkedNode *node = cache[key];     // 存在 找到这个key；
        moveToHead(node);                   // 移动到链表头部
        return node->value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            // 如果key不存在 创造一个新的节点
            DLinkedNode *node = new DLinkedNode(key,value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if(size > capacity){        // 如果超过容量
                DLinkedNode *removed = removeTail();    // 把真实的尾节点删除
                cache.erase(removed->key);              // 把哈希表中的也删除掉
                delete removed;
                --size;
            }
        }else{
            DLinkedNode *node = cache[key];     // key存在
            node->value = value;                // 更新key的值
            moveToHead(node);                   // 移动到链表头部
        }
    }

private:
    void addToHead(DLinkedNode *node){      // 在头部添加一个节点  新入
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode *node){     // 把这个节点删除掉
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode *node){       // 把某个节点移动到链表头部
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail(){              // 这个移除真的尾节点，不是初始化的那个尾节点
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }

};


int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
