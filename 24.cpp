#include<iostream>
#include<vector>

using namespace std;
// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int num,ListNode* next1 = nullptr){
        val = num;
        next = next1;
    }
};
void printNode(ListNode* haed){
    while(haed!=nullptr){
        cout<<haed->val<<" ";
        haed = haed->next;
    }
    cout<<endl;
}
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* cur = dummyNode;
        while(cur->next != nullptr && cur->next->next != nullptr){
            ListNode* temp = cur->next;
            ListNode* temp1 = cur->next->next->next;

            cur->next = cur->next->next;    //步骤一
            cur->next->next = temp;         // 步骤2
            cur->next->next->next = temp1;  //步骤3

            cur  = cur->next->next;
        }
        return dummyNode->next;

    }
};
int main(int argc, const char** argv) {
    vector<int> num = {4,3,2,1};
    ListNode* numberList = nullptr;
    for(int i = 0;i<num.size();i++){
        numberList = new ListNode(num[i],numberList);
    }
    while(numberList != nullptr){
        cout<<numberList->val<<" ";
        numberList = numberList->next;
    }
    cout<<endl;
    Solution sol;

    printNode(sol.swapPairs(numberList));

    system("pause");
    return 0;
}