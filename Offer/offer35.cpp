#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
请实现 copyRandomList 函数，复制一个复杂链表。
在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，
还有一个 random 指针指向链表中的任意节点或者 null。
*/



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

class Solution {
public:
    unordered_map<Node*,Node*> mp;
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        while(!mp.count(head)){
            Node *headNew = new Node(head->val);
            mp[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        return mp[head];
    }
};

int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
