#include<iostream>
#include<vector>
#include<functional>
using namespace std;

struct ListNode
{
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
/*
    给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {   //暴力解法 两次遍历
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        //printNode(dummyNode);
        ListNode* slow = dummyNode;
        ListNode* fast = dummyNode;
        while(n--){
            fast = fast->next;
        }
        fast = fast->next; //移动 n+1 个节点
        while(fast!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return dummyNode->next; 
       
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num = {5,4,3,2,1};
    ListNode* numberList = nullptr;
    for(int i=0;i<num.size();i++){
        numberList = new ListNode(num[i],numberList);
    }
    printNode(numberList);
    ListNode* ptr = numberList;
    int count;
    while(ptr!=0){
        ptr = ptr->next;
        count++;
    }
    cout<<count<<endl;
    Solution sol;
    ListNode* finalNode = sol.removeNthFromEnd(numberList,1);

    printNode(finalNode);
    system("pause");
    return 0;
}
