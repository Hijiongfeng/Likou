#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。
如果是，返回 true ；否则，返回 false 。
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
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        while(head){
            vec.push_back(head->val);
            head = head->next;
        }
        int left = 0,right = vec.size() - 1;
        while(left < right){
            if(vec[left] != vec[right])
                return false;
            left++;
            right--;
        } 
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1};
    ListNode *head = nullptr;
    for(int a : nums){
        head = new ListNode(a,head);
    }
    Solution sol;
    cout<<sol.isPalindrome(head)<<endl;

    system("pause");
    return 0;
}
