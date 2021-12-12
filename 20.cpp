#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(')');
            }else if(s[i]=='['){
                st.push(']');
            }else if(s[i]=='{'){
                st.push('}');
            }else if(st.top() == s[i]){  //如果相等  就弹出一个元素
                st.pop();
            }else{
                return false;
            }
        }
        return st.empty();  // true 的情况下  栈一定是空的
    }
};

int main(int argc, const char** argv) {
    string str = "()[]{}";
    Solution sol;
    cout<<sol.isValid(str)<<endl;
    system("pause");
    return 0;
}