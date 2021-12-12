#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int num,ListNode* next1 = nullptr){
        val = num;
        next = next1;
    }
};
//打印链表
void printNode(ListNode* head){
    while(head!=nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
//创建一个环形链表
ListNode* createCircleList(ListNode* head,int pos){   //pos 从0开始
    if(pos == -1) return head;
    ListNode* dummyNode = new ListNode(0);
    dummyNode->next = head;
    ListNode* cur = dummyNode;  
    while(pos--){
        cur = cur->next;
    }
    cur = cur->next;  //定位环的节点

    //定位尾节点的数值
    ListNode* ptr2 = dummyNode;
    int tailNum;
    while(ptr2->next != nullptr){
        ptr2 = ptr2->next;
    }
    tailNum = ptr2->val;

    ListNode* ptr = dummyNode;
    while(1){ 
    if(dummyNode->val == tailNum){
        dummyNode->next = cur;
        break;
    }else{
        dummyNode = dummyNode->next;
    }
    }
    //printNode(ptr->next);
    return ptr->next;
}
/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //ListNode* targetNode = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            //先判断有无环 +1 +2
            if(slow == fast){               
                ListNode* index1 = fast;
                ListNode* index2 = head;
                // 再次相遇为 环开始的节点
                while(index1 != index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return nullptr;     
    }
};


int main(int argc, const char** argv) {
    vector<int> num = {-4,0,2,3};
    ListNode* numberList = nullptr;
    for(int i=0;i<num.size();i++){
        numberList = new ListNode(num[i],numberList);
    }

    ListNode*ptr = createCircleList(numberList,1);

    //printNode(ptr);
    Solution sol;
    ListNode* targetNode = sol.detectCycle(ptr);
    printNode(targetNode);

    system("pause");
    return 0;
}