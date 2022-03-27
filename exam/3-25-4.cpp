#include<iostream>
#include<vector>

using namespace std;
/*
2022-3-25
地平线面试
让写一个合并两个有序链表

*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(){}
    ListNode(int a){
        val = a;
        next = nullptr;
    }
    ListNode(int a,ListNode *ne){
        val = a;
        next = ne;
    }
};

ListNode* constuct(ListNode *head1,ListNode *head2){
    ListNode *dummyNode = new ListNode(0);

    ListNode *cur = dummyNode;
    ListNode *cur1 = head1;
    ListNode *cur2 = head2;

    while(cur1 != nullptr && cur2 != nullptr){
        if(cur1->val == cur2->val){
            ListNode *node1 = new ListNode(cur1->val);
            ListNode *node2 = new ListNode(cur2->val);
            cur->next = node1;
            cur->next->next = node2;
            cur = cur->next->next;

            cur1 = cur1->next;
            cur2 = cur2->next;
            continue;
        }
        if(cur1->val < cur2->val){
            ListNode *node1 = new ListNode(cur1->val);
            cur->next = node1;

            cur = cur->next;
            cur1 = cur1->next;
            continue;
        }
        if(cur1->val > cur2->val){
            ListNode *node2 = new ListNode(cur2->val);
            cur->next = node2;

            cur = cur->next;
            cur2 = cur2->next;
            continue;
        }
    }

    while(cur1 != nullptr){
        ListNode *node1 = new ListNode(cur1->val);
        cur->next = node1;

        cur = cur->next;
        cur1 = cur1->next;
    }

    while(cur2 != nullptr){
        ListNode *node2 = new ListNode(cur2->val);
        cur->next = node2;

        cur = cur->next;
        cur2 = cur2->next;
    }

    return dummyNode->next;
}

int main(int argc, char const *argv[])
{
    
    vector<int> nums1 = {9,7,4,1};
    vector<int> nums2 = {10,8,5,5,1};
    ListNode *head1 = nullptr;
    for(auto & a:nums1){
        head1 = new ListNode(a,head1);
    }
    ListNode *head2 = nullptr;
    for(auto & a:nums2){
        head2 = new ListNode(a,head2);
    }

    ListNode *head = constuct(head1,head2);
    system("pause");
    return 0;
}
