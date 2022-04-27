#include<bits/stdc++.h>

using namespace std;

/*
给你一个单链表，随机选择链表的一个节点，并返回相应的节点值。每个节点 被选中的概率一样 。

实现 Solution 类：

Solution(ListNode head) 使用整数数组初始化对象。
int getRandom() 从链表中随机选择一个节点并返回该节点的值。链表中所有节点被选中的概率相等。
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {            // 哈希解法，
    vector<int> nums;
public:
    Solution(ListNode* head) {
        srand((unsigned)time(NULL));
        while(head){
            nums.emplace_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        int numIndex = rand() % nums.size();  // [0,n) 的随机数
        return nums[numIndex];
    }
};


/*
进阶：

如果链表非常大且长度未知，该怎么处理？
你能否在不使用额外空间的情况下解决此问题？

使用水塘抽样，保证每个数的概率一样
*/

class Solution2 {
    ListNode *_head;
public:
    Solution2(ListNode* head) {
        srand((unsigned)time(NULL));
        _head= head;
    }
    
    int getRandom() {
        int ans;
        int cnt = 0;
        ListNode* t = _head;
        while(t){
            cnt++;
            
            if(rand() % cnt == 0) ans = t->val;
            
            t = t->next;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {3,2,1};
    ListNode *head = nullptr;
    for(auto a : nums){
        head = new ListNode(a,head);
    }
    Solution2* sol = new Solution2(head);
    cout<<sol->getRandom()<<endl;
    system("pause");
    return 0;
}
