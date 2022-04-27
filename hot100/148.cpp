#include<bits/stdc++.h>

using namespace std;

/*
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        vector<int> vec;
        while(head){
            vec.push_back(head->val);
            head = head->next;
        }
        sort(vec.begin(),vec.end(),greater<int>());
        ListNode *newHead = nullptr;
        for(int a : vec){
            newHead = new ListNode(a,newHead);
        }
        return newHead;
    }

    ListNode* sortList2(ListNode* head) {  // 插入排序
        if(head == nullptr){
            return nullptr;
        }
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *lastSort = head;
        ListNode *cur = head->next;
        while(cur != nullptr){
            if(lastSort->val <= cur->val){
                lastSort = lastSort->next;
            }else{
                ListNode *prev = dummyHead;
                while(prev->next->val <= cur->val){
                    prev = prev->next;
                }
                lastSort->next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
            }
            cur = lastSort->next;
        }
        return dummyHead->next;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {3,1,2,4};
    ListNode *head = nullptr;
    for(int a : nums){
        head = new ListNode(a,head);
    }
    Solution sol;
    ListNode *ans = sol.sortList2(head);
    system("pause");
    return 0;
}
