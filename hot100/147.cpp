#include<bits/stdc++.h>

using namespace std;

/*
给定单个链表的头 head ，使用 插入排序 对链表进行排序，并返回 排序后链表的头 。

插入排序 算法的步骤:

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
下面是插入排序算法的一个图形示例。部分排序的列表(黑色)最初只包含列表中的第一个元素。
每次迭代时，从输入数据中删除一个元素(红色)，并就地插入已排序的列表中。

对链表进行插入排序。
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
    ListNode* insertionSortList(ListNode* head) {       // 链表的插入排序
        if(head == nullptr){
            return nullptr;
        }
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *lastSort = head;
        ListNode *cur = head->next;
        while(cur != nullptr){                  // 相当于 两次遍历
            if(lastSort->val <= cur->val){
                lastSort = lastSort->next;
            }else{
                ListNode *prev = dummyHead;
                while(prev->next->val <= cur->val){     // 找插入节点的位置
                    prev = prev->next;
                }
                lastSort->next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
            }
            cur = lastSort->next;
        }
        return dummyHead->next;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
