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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> st;
        for(int& a : nums){
            st.insert(a);
        }
        int ans = 0;
        bool flag = false;
        ListNode *pre = nullptr;
        while(head != nullptr){
            if(st.find(head->val) == st.end() && flag == true){
                flag = false;
                ans++;
            }else if(st.count(head->val)){
                flag = true;
            }
            pre = head;
            head = head->next;
        }
        if(st.find(pre->val) != st.end()){
            ans++;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> num = {2,1,0};
    ListNode* numberList = nullptr;
    for(int i=0;i<num.size();i++){
        numberList = new ListNode(num[i],numberList);
    }
    vector<int> nums = {0,1};
    Solution sol;
    cout<<sol.numComponents(numberList,nums)<<endl;

    system("pause");
    return 0;
}
