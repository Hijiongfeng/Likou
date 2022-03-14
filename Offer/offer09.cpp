#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

/*
用两个栈实现一个队列。队列的声明如下，
请实现它的两个函数 appendTail 和 deleteHead ，
分别完成在队列尾部插入整数和在队列头部删除整数的功能。
(若队列中没有元素，deleteHead 操作返回 -1 )
*/

class CQueue {
public:
    CQueue() {
        while(!st1.empty()){
            st1.pop();
        }
        while(!st2.empty()){
            st2.pop();
        }
    }
    
    void appendTail(int value) {
        st1.push(value);
    }
    
    int deleteHead() {
        if(st1.empty() && st2.empty()){
            return -1;
        }
        if(!st2.empty()){
            int res = st2.top();
            st2.pop();
            return res;
        }else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int res = st2.top();
        st2.pop();
        return res;
        //return res;
    }
private:
    stack<int> st1;     // 两个 栈 实现队列
    stack<int> st2;
};

int main(int argc, char const *argv[])
{
    CQueue *obj = new CQueue();
    obj->appendTail(1);
    obj->appendTail(2);
    obj->appendTail(3);
    obj->deleteHead();
    system("pause");
    return 0;
}
