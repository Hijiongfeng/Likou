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
给定一个链表，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

如果链表中存在环，则返回 true 。 否则，返回 false 。

*/
class Solution {
public:
    bool hasCycle(ListNode *head) {   //快慢双指针
        ListNode* slow = head;  
        ListNode* fast = head;
        while(fast !=nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){     // 应该为地址判断，值判断可能出错，可能为空值
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char** argv) {
    vector<int> num = {1,2};
    ListNode* numberList = nullptr;
    for(int i=0;i<num.size();i++){
        numberList = new ListNode(num[i],numberList);
    }

    ListNode*ptr = createCircleList(numberList,0);

    //printNode(ptr);
    Solution sol;
    cout<<sol.hasCycle(numberList)<<endl;

    system("pause");
    return 0;
}