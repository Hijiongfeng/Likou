#include<iostream>
#include<stack>
#include<deque>  //双端队列
#include<queue>     //队列

using namespace std;

class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int size = que1.size();
        size--;
        while(size--){
            que2.push(que1.front());
            que1.pop();
        }
        int res = que1.front();
        que1.pop();
        while(!que2.empty()){
            que1.push(que2.front());
            que2.pop();                 // 清空que2  把值给que1                                
        }
        return res;
    }
    
    int top() {
        return que1.back();
    }
    
    bool empty() {
        return que1.empty();
    }
public:
    queue<int> que1;
    queue<int> que2;  // 起一个复制到作用
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
