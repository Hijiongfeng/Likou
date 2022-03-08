#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<list>
using namespace std;

/*
优先级队列

队头元素 总是最大的
*/

void func(){

    std::priority_queue<int> value;
    value.push(1);
    value.push(3);
    value.push(4);
    value.push(2);

    while(!value.empty()){
        cout<<value.top()<<endl;
        value.pop();
    }

}

int main(int argc, char const *argv[])
{
    func();
    
    system("pause");
    return 0;
}
