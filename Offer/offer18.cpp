#include<iostream>
#include<vector>

using namespace std;

/*
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。

注意：此题对比原题有改动

示例 1:

输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

**/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(){}
    ListNode(int vall) : val(vall),next(nullptr){}
    ListNode(int vall,ListNode *ne) : val(vall),next(ne){}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) { 
        ListNode *dummyNode = new ListNode(0); 
        dummyNode->next = head;
        ListNode *cur = dummyNode;
        while(cur->next != nullptr){
            if(cur->next->val == val){
                ListNode *temp = cur->next;
                cur->next = cur->next->next;
            }else{
                cur = cur->next;
            }
        }
        return dummyNode->next;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
