#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int number,ListNode *next1 = nullptr){
        val = number;
        next = next1;
    }
};
//删除链表的某个元素
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* cur = dummyNode;
        while(cur->next != nullptr){
            if(cur->next->val == val){
                ListNode* temp = cur->next;   //都要保存一下要修改的节点
                cur->next = cur->next->next;
                delete temp;
            }else{
                cur=cur->next;
            }
        }
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};

int main(int argc, const char** argv) {
    vector<int> num = {7,7,7,7};
    ListNode *numberList = nullptr;
    for(int i=0;i<num.size();i++){
        numberList = new ListNode(num[i],numberList);
    }
    ListNode *ptr =numberList;
    while(ptr != nullptr){
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
    cout<<endl;

    Solution sol;
    ListNode* cur = sol.removeElements(numberList,7);
    ListNode* cur2 = cur;
    while(cur2 != nullptr){
        cout<<cur2->val<<" ";
        cur2 = cur2->next;
    }
    cout<<endl;

    system("pause");
    return 0;
}