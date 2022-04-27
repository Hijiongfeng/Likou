#include<bits/stdc++.h>

using namespace std;
/*
合并两个有序链表
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummyHead = new ListNode(-1);

        ListNode *_head = dummyHead;
        while(list1 != nullptr && list2!= nullptr){
            if(list1->val <= list2->val){
                _head->next = list1;
                list1 = list1->next;
            }else{
                _head->next = list2;
                list2 = list2->next;
            }
            _head = _head->next;
        }

        _head->next = list1 == nullptr ? list2:list1;
        return dummyHead->next;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
