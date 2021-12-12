#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int number,ListNode *next1 = nullptr){
        val = number;
        next = next1;
    }
};

class MyLinkList{
public:
    struct LinkNode{
        int val;
        LinkNode *next;
        LinkNode(int val):val(val),next(nullptr){}
    };
    MyLinkList(){
        _dummyHead = new LinkNode(0);
        _size = 0;
    }

    //获取第inedx个节点的数值，如果index为非法数值，则返回-1，index从0开始，头结点为第0个节点
    int get(int index){
        if(index > _size || index < 0){
            return -1;
        }
        LinkNode* cur = _dummyHead;
        while(index--){
            cur=cur->next;
        }
        cur=cur->next;
        return cur->val;
    }
    //在链表最前面插入一个节点，新节点成为链表的头结点
    void addAtHead(int val){ 
        LinkNode* newnode = new LinkNode(val);
        newnode->next = _dummyHead->next;
        _dummyHead->next = newnode;
        _size++;
    }
    //在链表的尾部插入一个节点
    void addAtTail(int val){
        LinkNode* newnode = new LinkNode(val);
        LinkNode*cur = _dummyHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newnode;
        _size++;
    }
    //在第index个节点插入一个新节点，例如index = 0 ；则新插入的节点为头结点
    void addAtIndex(int index,int val){
        if(index > _size || index < 0){
            return;
        }
        LinkNode* cur = _dummyHead;
        LinkNode* newnode = new LinkNode(val);
        while(index--){
            cur=cur->next;
        }
        newnode->next = cur->next;
        cur->next = newnode;
        _size++;
    }
    //删除第index个节点，如果index大于链表的长度，直接return index从0开始
    void deleteAtIndex(int index){
        if(index > _size || index < 0){
            return;
        }
        LinkNode* cur = _dummyHead;
        while(index--){
            cur=cur->next;
        }
        LinkNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        _size--;
    }
    //打印链表
    void printLinkNode(){
        LinkNode* cur=_dummyHead->next;
        while(_size--){
            cout<<cur->val<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
private:
    int _size;
    LinkNode *_dummyHead;
};

int main(int argc, const char** argv) {
    // vector<int> num = {6,5,4,3,2,1};
    // ListNode *numberList = nullptr;
    // for(int i=0;i<num.size();i++){
    //     numberList = new ListNode(num[i],numberList);
    // }
    // ListNode *ptr =numberList;
    // while(ptr != nullptr){
    //     cout<<ptr->val<<" ";
    //     ptr=ptr->next;
    // }

    MyLinkList mylist;
    mylist.addAtHead(1);
    mylist.addAtTail(3);
    mylist.addAtIndex(1,2);
    cout<<mylist.get(1)<<endl;
    mylist.printLinkNode();
    
    system("pause");
    return 0;
}