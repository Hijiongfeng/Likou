#include<bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int number,ListNode *next1 = nullptr){
        val = number;
        next = next1;
    }
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* formatList(ListNode* head) {
        // write code here
        if(head == nullptr) return nullptr;
        ListNode* newHead = new ListNode(head->val);
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = newHead;
        ListNode *temp1 = dummyNode->next;
        ListNode *temp2 = dummyNode;
        ListNode *cur = head->next;
        int i = 0;
        while(cur){
            ListNode *curry = new ListNode(cur->val);
            if(i % 2 == 0){
                temp1->next = curry;
                temp1 = temp1->next;
            }else{
                curry->next = temp2->next;
                temp2->next = curry;
            }
            cur = cur->next;
            i++;
        }
        return dummyNode->next;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num = {5,4,3,2,1};
    ListNode *numberList = nullptr;
    for(int i=0;i<num.size();i++){
        numberList = new ListNode(num[i],numberList);
    }

    Solution sol;
    ListNode *hh = sol.formatList(numberList);

    system("pause");
    return 0;
}
