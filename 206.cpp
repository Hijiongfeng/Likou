#include<iostream>
#include<vector>

using namespace std;
//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int number,ListNode* next1 = nullptr){
        val  = number;
        next = next1;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {  //双指针实现链表的翻转
        ListNode* temp;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

int main(int argc, const char** argv) {
    vector<int> num = {5,4,3,2,1};
    ListNode* numberList = nullptr; //初始化一个空指针
    for(int i=0;i<num.size();i++){
        numberList = new ListNode(num[i],numberList);
    }
    ListNode* ptr = numberList;
    while(ptr != nullptr){
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }
    cout<<endl;

    Solution sol;
    ListNode* ptr2 = sol.reverseList(numberList);
    while(ptr2 != nullptr){
        cout<<ptr2->val<<" ";
        ptr2 = ptr2->next;
    }
    cout<<endl;

    system("pause");
    return 0;
}