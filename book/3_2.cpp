#include<iostream>
#include<vector>

using namespace std;

/*
实现一个链表
*/


template<typename Object>
class List{
private:
    struct Node
    {
        Object data;
        Node *prev;
        Node *next;

        Node(const Object & d = Object{} , Node * p = nullptr,Node * n = nullptr)
        : data(d) , prev(v) , next(n); 
        {}

        Node(Object && d,Node * p = nullptr,Node * n = nullptr)
        : data(std::move(d)) , prev(p) , next(n)
        {}
    };
    
public:
    class const_iterator{                   // 常量迭代器的 类
    
    public:
        const_iterator() : current(nullptr){

        }

        const Object & operator*() const{       // 重载 * 号，迭代器 返回数据
            return retrieve();
        }

        const_iterator & operator++(){          // 重载 ++ 迭代器 增加
            current = current->next;
            return *this;
        }

        const_iterator operator++(int){
            const_iterator old = *this;
            ++(*this);
            return old;
        }


        bool operator==(const const_iterator & rhs) const{      // 重载 == ，判断迭代器 是否相等
            return current == rhs.current;
        }

        bool operator!=(const const_iterator & rhs) const{      // 重载 ！= ，判断迭代器 是否不相等
            return !(*this == rhs);
        }

    protected:
    //public:
        Node *current;
        Object & retrieve() const{
            return current->data;
        }
        const_iterator(Node *p): current(p)         // 有参 构造
        {

        }

        friend class List<Object>;
    };

    class iterator : public const_iterator{
    public:
        iterator(){

        }

        Object & operator*(){
            return const_iterator::retrieve();
        }

        const Object & operator*() const{
            return const_iterator::operator*();
        }

        iterator & operator++(){
            this->current = this->current->next;
            return *this;
        }

        iterator & operator++(int){
            iterator old = *this;
            ++(*this);
            return old;
        }

    protected:
        iterator(Node *p) : const_iterator(p){

        }

        friend class List<Object>;

    };


public:

    List(){
        init();
    }

    ~List(){
        clear();
        delete head;
        delete tail;
    }

    List(const List & rhs){         // 拷贝构造函数
        init();
        for(auto & x : rhs){
            push_back(x);
        }
    }

    List(List && rhs) : theSize(rhs.theSize) , head(rhs.head),tail(rhs.tail)    // 移动构造函数
    {
        rhs.theSize = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }

    List & operator=(const List & rhs){
        List copy = rhs;
        std::swap(*this,copy);
        return *this;
    }

    

private:
    int theSize;
    Node *head;
    Node *tail;

    void init(){
        theSize = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
