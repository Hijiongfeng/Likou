#include<bits/stdc++.h>

using namespace std;

/*
请编写一个函数，用于 删除单链表中某个特定节点 。
在设计函数时需要注意，你无法访问链表的头节点 head ，只能直接访问 要被删除的节点 。

题目数据保证需要删除的节点 不是末尾节点 。

*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;        // 把当前节点的值 改为下一个节点的值
        node->next = node->next->next;      // 删除下一个节点；；
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
