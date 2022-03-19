#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的
最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stA.push(x);
        if(stB.empty()){
            stB.push(x);
        }else{
            if(stB.top() >= x ){    // 栈B顶 存储最小的元素
                stB.push(x);
            }
        }
    }
    
    void pop() {
        int x = stA.top();
        stA.pop();
        if(stB.top() == x){     // 删除的时候，要看删除的是不是 栈B顶的元素
            stB.pop();
        }
    }
    
    int top() {
        return stA.top();
    }
    
    int min() {
        return stB.top();
    }
private:
    stack<int> stA;         // 存储数据
    stack<int> stB;         // 辅助 栈
};


int main(int argc, char const *argv[])
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout<<minStack.min()<<endl;   //--> 返回 -3.
    minStack.pop();
    cout<<minStack.top()<<endl;     // --> 返回 0.
    cout<<minStack.min()<<endl;   //--> 返回 -2.

    system("pause");
    return 0;
}
