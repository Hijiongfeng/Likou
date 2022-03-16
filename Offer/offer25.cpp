#include<iostream>
#include<vector>

using namespace std;

/*
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x,ListNode *l) : val(x), next(l) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummyNode = new ListNode(0);

        ListNode *cur = dummyNode;
        ListNode *left = l1;
        ListNode *right = l2;

        while(left != nullptr && right != nullptr){
            if(left->val == right->val){
                ListNode *node1 = new ListNode(left->val);
                ListNode *node2 = new ListNode(right->val);
                cur->next = node1;
                cur->next->next = node2;
                cur = cur->next->next;
                left = left->next;
                right = right->next;
                continue;
            }
            if(left->val < right->val){
                ListNode *node1 = new ListNode(left->val);
                cur->next = node1;
                cur = cur->next;
                left = left->next;
                continue;
            }
            if(left->val > right->val){
                ListNode *node2 = new ListNode(right->val);
                cur->next = node2;
                cur = cur->next;
                right = right->next;
                continue;
            }
        }
        while(left != nullptr){
            ListNode *node1 = new ListNode(left->val);
            cur->next = node1;
            cur = cur->next;
            left = left->next;
        }
        while(right!= nullptr){
            ListNode *node2 = new ListNode(right->val);
            cur->next = node2;
            cur = cur->next;
            right = right->next;
        }
        return dummyNode->next;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num1 = {4,2,1};
    ListNode* numberList1 = nullptr;
    for(int i=0;i<num1.size();i++){
        numberList1 = new ListNode(num1[i],numberList1);
    }

    vector<int> num2 = {4,3,1};
    ListNode* numberList2 = nullptr;
    for(int i=0;i<num2.size();i++){
        numberList2 = new ListNode(num2[i],numberList2);
    }

    Solution sol;
    ListNode *vec = sol.mergeTwoLists(numberList1,numberList2);

    system("pause");
    return 0;
}
