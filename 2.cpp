#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
给你两个 非空 的链表，表示两个非负的整数。
它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    vector<int> vec;
    void addList(ListNode* l1,ListNode* l2){
        
        if(l1 == nullptr ) return;

        if(l1!= nullptr && l2!=nullptr){
            int value = l1->val + l2->val;
            if(value >= 10){
                l1->val = value % 10;
                if(l1->next){
                    l1->next->val = l1->next->val + (value / 10);
                }else{
                    ListNode* node = new ListNode(value / 10);
                    l1->next = node;
                }
                
            }else{
                l1->val = value;
            }
            
        }
        vec.push_back(l1->val);
        if(l2!=nullptr){
            addList(l1->next,l2->next);
        }
        else{
            addList(l1->next,nullptr);
        }
        
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0,len2 = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1!=nullptr){
            len1++;
            temp1 = temp1->next;
        }
        while(temp2!=nullptr){
            len2++;
            temp2 = temp2->next;
        }

        if(len2 > len1)
            swap(l1,l2);
        ListNode* temp3 = l2;
        int gap = len1 - len2;
        while(gap--){
            ListNode* node = new ListNode(0);
            temp3->next = node;
            temp3 = temp3->next;
        }
        
        addList(l1,l2);

        ListNode* res = nullptr;
        reverse(vec.begin(),vec.end());
        for(auto & a : vec){
            res = new ListNode(a,res);
        }
        return res;
    }

};


int main(int argc, char const *argv[])
{
    vector<int> num1 = {9,9,9};
    vector<int> num2 = {9};
    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;
    for(auto & a : num1){
        l1 = new ListNode(a,l1);
    }
    for(auto & b : num2){
        l2 = new ListNode(b,l2);
    }
    Solution sol;
    ListNode* res = sol.addTwoNumbers(l1,l2);
    system("pause");
    return 0;
}
