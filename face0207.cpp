#include<iostream>
#include<vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int num,ListNode *nextl=nullptr){
        val=num;
        next = nextl;
    }
};

void printNode(const ListNode *head){
    int count = 0;
    while(head!=nullptr){
        count++;
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    cout<<"list length: "<<count<<endl;
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = 0;
        int countB = 0;
        ListNode *newA = headA;
        ListNode *newB = headB;
        while(newA != nullptr){
            newA = newA->next;
            countA++;
        }
        while(newB != nullptr){
            newB = newB->next;
            countB++;
        }
        newA = headA;    //改变了指向  需重新指定
        newB = headB;
        if(countB>countA){  // 让 A 为 长链表的长度
            swap(countA,countB);
            swap(newA,newB);
        }
        int gap = countA-countB;
        while(gap--){
            newA = newA->next;
        }
        while(newA != nullptr){
            if(newA == newB){
                return newA;
            }
            else{
                newA = newA->next;
                newB = newB->next;
            }
        }
        return nullptr;
    }
};

int main(int argc, const char** argv) {
    vector<int> arr = {5,4,3,2,1};
    ListNode *numList = nullptr;
    for(int i=0;i<arr.size();i++){
        numList = new ListNode(arr[i],numList);
    }
    printNode(numList);
    system("pause");
    return 0;
}