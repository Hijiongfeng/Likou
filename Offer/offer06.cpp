#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x,ListNode *ne) : val(x), next(ne) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        if(head == nullptr) return res;
        while(head != nullptr){
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {3,2,1};
    ListNode *head = nullptr;
    for(auto & a : nums){
        head = new ListNode(a,head);
    }
    Solution sol;
    vector<int> vec = sol.reversePrint(head);
    for(int i = 0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    system("pause");
    return 0;
}
