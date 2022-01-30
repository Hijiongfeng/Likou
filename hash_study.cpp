#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

/*
构造一个 哈希表/散列表 
理解上可以理解成C++中的unordered_set
构造方法采用 除留余数法
解决冲突的方法采用 开放定址法的线性探测法
*/

const int NULLKEY = INT32_MIN;

class HashTable{
    int *_elme;
    int _size;

public:
    HashTable(int size):_size(size){
        cout<<"Hash Table()"<<endl;
        _elme = (int*)malloc(_size*sizeof(int));    //  分配 大小
        for(int i = 0;i<_size;i++){
            _elme[i] = NULLKEY;
        }
    }

    int Hash(int key){      //哈希函数的构造方法，采用除留余数法, 这里并没有 采用 最大的质数
        return key % _size;  //将Key除以p得到的值作为Value存储地址，通常p是小于哈希表长的最大质数。
    }

    void insert(int key){       //这里 key 与 value 的值相同 相当于 unordered_set
        int addr = Hash(key);
        while(_elme[addr] != NULLKEY){  // 如果一开始 这个位置 不是NULLKEY 这证明 发生了冲突
            addr = (addr + 1) % _size;  //如果发生冲突，那么采用开放地址法中的线性探测法
        }
        _elme[addr] = key;
    }

    bool search(int key){
        int addr = Hash(key);
        while(_elme[addr] != key){
            if(_elme[addr] == NULLKEY){
                return false;
            }
            addr = (addr + 1) % _size;
            if(addr == Hash(key)){
                return false;
            }
        }
        return true;
    }

    void remove(int key){               // 移除一个元素
        for(int i = 0;i<_size;i++){         
            if(_elme[i] == key){
                _elme[i] = NULLKEY;
            }
        }
    }
    
    void print() const{
        for(int i = 0;i<_size;i++){     // 打印 判断是否空
            if(_elme[i] != NULLKEY){
                cout<<i<<" "<<_elme[i]<<endl;
            }else{
                cout<<i<<" "<<endl;
            }
        }
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val,ListNode *next = NULL):val(val),next(next){}
};

class HashTable2{       // 拉链法 解决哈希冲突
private:
    // int *_elme;
    int _size;
    ListNode* hash_table[1000];  // 代表链表数组   // 最大长度  
    //ListNode* hash_table[];  
public:
    HashTable2(int size):_size(size){       // 初始化
        cout<<"Hash Table2()"<<endl;
        // _elme = (int*)malloc(_size*sizeof(int));    // 分配大小
        for(int i = 0;i<_size;i++){
            hash_table[i] = nullptr;
        }
    }

    int Hash(int key){
        return key % _size;
    }

    void insert(int key){
        int addr = Hash(key);
        ListNode* np = new ListNode(key);
        if(np == nullptr) return;
        //np->next = hash_table[addr];
        if(hash_table[addr] != nullptr){
            ListNode *node = hash_table[addr];
            while(node->next != nullptr){
                node = node->next;
            }
            node->next = np;
        }else{
            hash_table[addr] = np;
        }
    }

    bool search(int key){
        int addr = Hash(key);
        ListNode *node = hash_table[addr];
        while(node!=nullptr){
            if(node->val == key){
                return true; 
            }
            node = node->next;
        }
        return false;
    }

    void remove(int key) {  // 移除一个元素

        int addr = Hash(key);
        ListNode *np = hash_table[addr];

        if(np == nullptr){
            cout<<"can not find this elme "<<endl;
            return;
        }

        ListNode *cur = np;

        if(np->val == key){      // 如果第一个元素是要删除的元素
            np = np->next;
        }

        while(cur->next != nullptr){        // 第一个元素不是，查找后面的元素
            if(cur->next->val == key){
                cur->next = cur->next->next;
            }else{
                cur = cur->next;
            }
        }

        hash_table[addr] = np;  // 更新 哈希链表

    } 

    void print(){
        for(int i = 0;i<_size;i++){
            cout<<"["<<i<<"]:";
            ListNode *head = hash_table[i];
            while(head){
                cout<<" -> "<<head->val;
                head = head->next;
            }
            cout<<endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    // vector<int> nums{12, 67, 56, 16, 25, 37, 22, 29, 15, 47, 48, 34};
    // HashTable hashtable(nums.size());
    // for (auto& e: nums)
    //     hashtable.insert(e);
    // hashtable.print();

    // cout<<hashtable.search(100)<<endl;
    vector<int> nums{12, 67, 56, 16, 25, 37, 22, 29, 15, 47, 48, 34};
    HashTable hashtable(nums.size());

    for(auto& e:nums){
        hashtable.insert(e);
    }
    hashtable.print();
    //cout<<hashtable.search(67)<<endl;
    cout<<"*****"<<endl;
    hashtable.remove(12);
    hashtable.print();
    system("pause");
    return 0;
}
