#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

/*
输入两个整数序列，第一个序列表示栈的压入顺序，
请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如，序列 {1,2,3,4,5} 是某栈的压栈序列，
序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，
但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st1;
        queue<int> que1;
        for(int i = 0;i<popped.size();i++){
            que1.push(popped[i]);
        }
        for(auto & a:pushed){
            st1.push(a);
            while(!st1.empty() && st1.top() == que1.front()){
             
                st1.pop();
                que1.pop();
 
            }
        }
        if(st1.empty()) return true;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> pushed = {1,2,3,4,5};
    vector<int> poped = {4,5,3,2,1};
    Solution sol;
    cout<<sol.validateStackSequences(pushed,poped)<<endl;
    system("pause");
    return 0;
}
